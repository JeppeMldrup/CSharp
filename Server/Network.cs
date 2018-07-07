using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

namespace Server{
  public class Network
  {
    public TcpListener server;

    int port = 2345;
    IPAddress localAddr = IPAddress.Parse("127.0.0.1");
    int bytes = 0;

    public void InitServer()
    {
      server = new TcpListener(localAddr, port);
      server.Start();
      server.BeginAcceptTcpClient(OnClientConnect, null);
      Console.WriteLine("Server started");
    }

    void OnClientConnect(IAsyncResult result)
    {
      TcpClient client = server.EndAcceptTcpClient(result);
      Console.WriteLine("Client connected");

      for (int i = 1; i < Globals.maxPlayers; i++)  // Insert the newly connected client into the client array
      {
        if (Globals.clients[i] == null){
          Globals.clients[i] = new Client(client.Client.RemoteEndPoint.ToString(), i, client);
          Console.WriteLine("Incoming Connection from " + Globals.clients[i].IP + "|| Index: " + i);
          return;
        }
      }
    }
  }
}
