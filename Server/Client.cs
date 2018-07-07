using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

namespace Server{
  public class Client{

    public string ip;
    public int index;
    public TcpClient socket;
    public NetworkStream stream;

    private byte[] data = new byte[Globals.bufferSize];

    public Client(string _ip, int _index, TcpClient _Socket){
      ip = _ip;
      index = _index;
      socket = _Socket;

      socket.SendBufferSize = Globals.bufferSize;
      socket.ReceiveBufferSize = Globals.bufferSize;
      stream = socket.GetStream();
      stream.BeginRead(data, 0, Globals.bufferSize, OnRecieveData, stream);
    }

    void OnRecieveData(IAsyncResult result){
      int bytes = stream.EndRead(result);  // Gets the length of the actual data

      string clientData;
      clientData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);  // Encode data into a string
      Console.WriteLine("Received: {0}", clientData);

      byte[] response = System.Text.Encoding.ASCII.GetBytes("Response");  // respond to the client
      stream.Write(response, 0, response.Length);
    }
  }
}
