//#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include "httplib.h"
//#include <nlohmann/json.hpp>
//
//using json = nlohmann::json;
//
//struct Name {
//	std::string title;
//	std::string first;
//	std::string last;
//
//	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Name, title, first, last);
//};

#include "Networking.h"

int main()
{
	Networking networking;
	std::cout << networking.networkConnection_QuickMode() << std::endl;
	std::cout << networking.networkConnection_AdvancedMode() << std::endl;
	/*httplib::Client cli("https://randomuser.me");
	if (auto res = cli.Get("/api/"))
	{
		std::cout << res->status << std::endl;
		std::cout << res->body << std::endl;

		auto j = json::parse(res->body);
		std::string titlu = j["results"][0]["name"]["title"];
		std::string first = j["results"][0]["name"]["first"];
		std::string last = j["results"][0]["name"]["last"];
		std::cout << titlu << "\n";
		std::cout << first << "\n";
		std::cout << last << "\n";

		Name name = j["results"][0]["name"].get<Name>();
		std::cout << name.title << "\n";
		std::cout << name.last << "\n";
		std::cout << name.first << "\n";
	}*/

	return 0;
}