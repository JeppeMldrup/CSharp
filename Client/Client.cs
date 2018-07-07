using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

class Client
{
  public void Connect(String server)
  {
    try
    {
      Int32 port = 2345;
      TcpClient client = new TcpClient("127.0.0.1", port);

      int bufferSize = 1024;

      String message = (String)client.Client.RemoteEndPoint.ToString();
      Byte[] data = System.Text.Encoding.ASCII.GetBytes(message);

      NetworkStream stream = client.GetStream();  //Get the clients stream

      stream.Write(data, 0, data.Length);  //Send the message to the connected server

      Console.WriteLine("Sent: {0}", "Hello boi");

      // Receive the TcpServer.response.

      // Buffer to store the response bytes.
      data = new Byte[bufferSize];

      // String to store the response ASCII representation.
      String responseData = String.Empty;

      // Read the first batch of the TcpServer response bytes.
      Int32 bytes = stream.Read(data, 0, data.Length);
      responseData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
      Console.WriteLine("Received: {0}", responseData);
    }
    catch (Exception e)
    {
      Console.WriteLine(e.ToString());
    }
  }
}
