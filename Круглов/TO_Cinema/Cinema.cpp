#include"Cinema.h"

using namespace std;

void Cinema::addSession(const Session& session) {
	Sessions.push_back(session);
}

bool Cinema::deleteSession(const Session& session) {
	for (int i = 0; i < Sessions.size(); i++)
	{
		if (Sessions[i] == session)
		{
			Sessions.erase(Sessions.begin() + i);
			return true;
		}
	}
	return false;
}