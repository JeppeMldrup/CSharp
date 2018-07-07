using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

namespace Server{
  public class Globals{
    public static Globals instance = new Globals();

    // Global classes
    public static Client[] clients = new Client[100];
    public static Network server = new Network();

    //Global variables
    public const int bufferSize = 1024;
    public const int maxPlayers = 100;
  }
}
