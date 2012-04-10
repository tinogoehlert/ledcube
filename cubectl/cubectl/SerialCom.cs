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
		public byte[]	getBuffer(){
			byte[] tmp = new byte[18];
			tmp[0] = cmd; 
			tmp[1] = len;
			buf.CopyTo(tmp, 2);
			return tmp;
		}
	}
	
	public delegate void sercom_exception(Exception e);
	public delegate void sercom_message_cmd(Command c);
	public delegate void sercom_message_str(string stat);
	
	// TODO: rename SerialCom to CubeCom ;I
	public static class SerialCom
	{
		static public string    CurrentPort = string.Empty;
		
		static public event sercom_exception CubeEvent_Exception;
		static public event sercom_message_cmd CubeEvent_Sent;
		static public event sercom_message_cmd CubeEvent_Recv;
		static public event sercom_message_str CubeEvent_Stat;
		
		static Queue<Command> 	cmdlist = new Queue<Command>();
		static int				_baud	= 9600;
		
		static public void Init ()
		{
			if(SerialPort.GetPortNames().Length > 0)
				CurrentPort = SerialPort.GetPortNames()[0];
		}
		
		static public int AddCommand(byte cmd)
		{
			cmdlist.Enqueue(new Command{cmd = cmd, len = 0});
			return cmdlist.Count;
		}
		
		static public int AddCommand(byte cmd, string buff)
		{
			if(buff.Length >= 16){
				throw new Exception("text too long! :(");
			}
			
			System.Text.ASCIIEncoding enc = new System.Text.ASCIIEncoding();
    		
			cmdlist.Enqueue(new Command{cmd = cmd, 
									len = Convert.ToByte(buff.Length), 
									buf = enc.GetBytes(buff)});
			return cmdlist.Count;
		}
		
		static public void ProcessCommands()
		{
			try{
				Command c  = null;
				if((c = cmdlist.Dequeue()) != null){
					if(CurrentPort != string.Empty){
						SerialPort port = new SerialPort(CurrentPort, 
						                                 _baud, 
						                                 Parity.None, 
						                                 8, 
						                                 StopBits.One);
						port.Open();
						byte[] b = c.getBuffer();
						port.Write(b,0,18);
					}else{
						throw(new Exception("no Serialport selected or found"));	
					}
				}
			}catch(Exception e){
				if(CubeEvent_Exception != null) CubeEvent_Exception(e);	
			}
		}
	}
}

