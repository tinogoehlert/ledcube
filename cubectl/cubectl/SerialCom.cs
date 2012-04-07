using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Threading;

namespace cubectl
{
	public class Command{
		public byte 	cmd;
		public byte 	len;
		public byte[]	buf = new byte[16];
	}
	
	public static class SerialCom
	{
		static SerialPort _port  = new SerialPort();
		static string     _ident = string.Empty;
		
		
		static public void Init ()
		{
			if(SerialPort.GetPortNames().Length > 0)
				_ident = SerialPort.GetPortNames()[0];
		}
	}
}

