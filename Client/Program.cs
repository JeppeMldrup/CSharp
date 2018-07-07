using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

class Program
{
  public static void Main(){
    Client client = new Client();
    client.Connect("127.0.0.1");
  }
}
