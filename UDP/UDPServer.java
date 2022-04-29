import java.io.*;
import java.net.*;

class UDPServer 
{
  public static void main (String args[]) throws Exception
  {
    DatagramSocket ss = new DatagramSocket (7999);

      System.out.println ("SERVER RUNNING");
    while (true)
      {
        byte[]receiveData = new byte[1024];
        byte[] sendData = new byte[1024];
        DatagramPacket receivePacket = new DatagramPacket (receiveData, receiveData.length);
        String message = "";
        String modifiedmsg = "";
        ss.receive (receivePacket);

        message = new String (receivePacket.getData ());

        InetAddress IPAddress = receivePacket.getAddress ();
        int port = receivePacket.getPort ();

        System.out.println ("FR0M Client" + IPAddress + ": " + message);
        modifiedmsg = message.toUpperCase ();
        sendData = modifiedmsg.getBytes ();
        DatagramPacket sendPacket =
        new DatagramPacket (sendData, sendData.length, IPAddress, port);
        ss.send (sendPacket);

        System.out.println ("Data Sent successfully");
      }
  }
}

