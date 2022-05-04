#include "Client.h"
#include "LocalClient.h"
#include "ForeignClient.h"

void contactClient(Client *client)
{
  cout << "\x1B[36m";
  cout << client->getName() << endl;
  cout << "\033[0m";
  client->generateInvoice();
  client->phoneToClient();
  cout << endl;
}

void clientsManager()
{
  size_t clientSize = Utilities::randomNumber(1, 10);
  Client *clients[clientSize];
  for (size_t i = 0; i < clientSize; i++)
  {
    bool isExternal = Utilities::randomNumber(0, 1);
    size_t randomPhoneNumber = Utilities::randomNumber(100000000, 999999999);
    if (isExternal)
    {
      clients[i] = new LocalClient("LocalClient", randomPhoneNumber, 3);
    }
    else
    {
      clients[i] = new ForeignClient("ForeignClient", randomPhoneNumber, 10, "US", "USD", "+1");
    }
  }

  for (size_t i = 0; i < clientSize; i++)
  {
    contactClient(clients[i]);
  }

  for (size_t i = 0; i < clientSize; i++)
  {
    delete clients[i];
  }
}
