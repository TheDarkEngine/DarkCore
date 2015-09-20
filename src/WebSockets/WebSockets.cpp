#include <DarkCore.hpp>

namespace WebSockets
{
	static int callback_http(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
	{
		return 0;
	}

	static int callback_dew_rcon(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
	{
		switch (reason) {
		case LWS_CALLBACK_ESTABLISHED: {
			Logging::Debug::WriteToLog("Websocket Event (LWS_CALLBACK_ESTABLISHED)");
			break;
		}
		case LWS_CALLBACK_RECEIVE: {
			//TODO: Call functions in C from the command asked by the user.
			rapidjson::Document d;
			d.Parse(std::string((char *)in).c_str());

			rapidjson::Value& command = d["command"];
			std::string send = "I got your message. You sent me " + std::string(command.GetString());

			Logging::Debug::WriteToLog("Websocket Event (LWS_CALLBACK_RECEIVE): %s", std::string((char *)in).c_str());

			unsigned char *sendChar = (unsigned char*)malloc(LWS_SEND_BUFFER_PRE_PADDING + send.length() + LWS_SEND_BUFFER_POST_PADDING);
			for (size_t i = 0; i < send.length(); i++) {
				sendChar[LWS_SEND_BUFFER_PRE_PADDING + i] = send.c_str()[i];
			}
			libwebsocket_write(wsi, &sendChar[LWS_SEND_BUFFER_PRE_PADDING], send.length(), LWS_WRITE_TEXT);
			free(sendChar);
			break;
		}
		case LWS_CALLBACK_CLOSED: {
			Logging::Debug::WriteToLog("Websocket Event (LWS_CALLBACK_CLOSED)");
			break;
		}
		default:
			break;
		}
		return 0;
	}

	static struct libwebsocket_protocols protocols[] = {
		{
			"http-only",         // name
			callback_http,       // callback
			0                    // per_session_data_size
		},
		{
			"darkpacket",        // protocol name - very important!
			callback_dew_rcon,   // callback
			0                    // we don't use any per session data
		},
		{
			NULL, NULL, 0
		}
	};

	bool ServerRunning = FALSE;
	void Server::Stop()
	{
		ServerRunning = FALSE;
		return;
	}
	DWORD WINAPI Server::Start(LPVOID) {
		ServerRunning = TRUE;
		int port = 13337;
		struct libwebsocket_context *context;
		int opts = 0;
		char interface_name[128] = "";
		const char * interfacez = NULL;

		Logging::Debug::WriteToLog("WebSockets::Server::Start: Initializing WebSocket Server on Port %i", port);

		//TODO: implement https/ssl later
		const char *cert_path = "/libwebsockets-test-server.pem";
		const char *key_path = "/libwebsockets-test-server.key.pem";

		//TODO: if (!use_ssl)
		cert_path = key_path = NULL;

		context = libwebsocket_create_context(port, interfacez, protocols,
			libwebsocket_internal_extensions,
			cert_path, key_path, NULL, -1, -1, opts);

		if (context == NULL) {
			Logging::Debug::WriteToLog("StartWebSocketServer: libwebsocket init failed");
			return -1;
		}


		// infinite loop, to end this server send SIGTERM. (CTRL+C)
		while (ServerRunning) {
			libwebsocket_service(context, 50);
			// libwebsocket_service will process all waiting events with their
			// callback functions and then wait 50 ms.
			// (this is a single threaded webserver and this will keep our server
			// from generating load while there are not requests to process)
		}
		Logging::Debug::WriteToLog("StartWebSocketServer: libwebsocket cleaned up");

		libwebsocket_context_destroy(context);
		return 0;
	}
}