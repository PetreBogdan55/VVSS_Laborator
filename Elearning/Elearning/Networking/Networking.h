#pragma once

#include <iostream>
#include <string>

#include "Windows.h"
#include "wininet.h"
#include "objbase.h"
#include "netlistmgr.h"

#pragma comment(lib, "Wininet.lib")
#include "LoggerSingleton.h"

class Networking
{
public:
	enum class INTERNET_STATUS {
		CONNECTED,
		DISCONNECTED,
		CONNECTED_TO_LOCAL,
		CONNECTION_ERROR
	};

	INTERNET_STATUS isConnectedToInternet() const;

	bool networkConnection_QuickMode() const;
	bool networkConnection_AdvancedMode() const;
};

