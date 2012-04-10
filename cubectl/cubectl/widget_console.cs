using System;
using Gtk;
using Pango;

namespace cubectl
{
	public enum SerialDirection{
		SERIAL_RECV = 0x01,
		SERIAL_SENT = 0x02,
		SERIAL_STAT = 0x03
	}
	
	[System.ComponentModel.ToolboxItem(true)]
	public partial class widget_console : Gtk.Bin
	{
		
		FontDescription pangofont = new FontDescription();
        TextTag ptag_sermon_recv = new TextTag("sermon_recv");
        TextTag ptag_sermon_sent = new TextTag("sermon_sent");
        TextTag ptag_sermon_stat = new TextTag("sermon_stat");
		
        TextTag ptag_exception_reason = new TextTag("exception_reason");
        TextTag ptag_exception_message = new TextTag("exception_message");
		
		public widget_console ()
		{
			this.Build ();
		
			textview_sermon.ModifyBase(StateType.Normal, new Gdk.Color(0x0f, 0x0f, 0x0f));
            textview_errors.ModifyBase(StateType.Normal, new Gdk.Color(0x0f, 0x0f, 0x0f));

            pangofont.Family = "Consolas";
            pangofont.AbsoluteSize = 12 * Pango.Scale.PangoScale;

            textview_sermon.ModifyFont(pangofont);
            textview_errors.ModifyFont(pangofont);

            textview_sermon.ModifyText(StateType.Normal, new Gdk.Color(0xff, 0xff, 0xff));
            textview_errors.ModifyText(StateType.Normal, new Gdk.Color(0xff, 0xff, 0xff));
			
            ptag_sermon_stat.ForegroundGdk = new Gdk.Color(0xB3, 0xEE, 0x3A);
            ptag_sermon_recv.ForegroundGdk = new Gdk.Color(0xFF, 0xFF, 0xE0);
			ptag_sermon_sent.ForegroundGdk = new Gdk.Color(0xFF, 0xFF, 0xE0);
			ptag_exception_reason.Foreground = "darkred";
			ptag_exception_message.Foreground = "red";
			
			textview_sermon.Buffer.TagTable.Add(ptag_sermon_stat);
            textview_sermon.Buffer.TagTable.Add(ptag_sermon_recv);
            textview_sermon.Buffer.TagTable.Add(ptag_sermon_sent);
            
            textview_errors.Buffer.TagTable.Add(ptag_exception_reason);
            textview_errors.Buffer.TagTable.Add(ptag_exception_message);
		}
		
		public void printException(Exception e)
        {
            Gtk.Application.Invoke(delegate
            {
                var iter = textview_errors.Buffer.GetIterAtLine(textview_errors.Buffer.LineCount - 1);
                textview_errors.Buffer.InsertWithTagsByName(ref iter, e.TargetSite + Environment.NewLine, "exception_reason");
                textview_errors.Buffer.InsertWithTagsByName(ref iter, e.Message + Environment.NewLine, "exception_message");
            	textview_errors.Buffer.Insert(ref iter, Environment.NewLine);
			});
        }
		
		public void printSerial(cubectl.Command cmd, SerialDirection dir)
        {
			Gtk.Application.Invoke(delegate
            {
                var iter = textview_sermon.Buffer.GetIterAtLine(textview_sermon.Buffer.LineCount - 1);
				switch(dir){
				case SerialDirection.SERIAL_RECV:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            cmd.buf + Environment.NewLine, 
					                                            "sermon_recv");
					break;
				case SerialDirection.SERIAL_SENT:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            cmd.buf + Environment.NewLine, 
					                                            "sermon_sent");
					break;
				case SerialDirection.SERIAL_STAT:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            cmd.buf + Environment.NewLine, 
					                                            "sermon_stat");
					break;
				}
			});
        }
		
		public void printSerial(string str, SerialDirection dir)
		{
			Gtk.Application.Invoke(delegate
		    {
		        var iter = textview_sermon.Buffer.GetIterAtLine(textview_sermon.Buffer.LineCount - 1);
				switch(dir){
				case SerialDirection.SERIAL_RECV:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            str + Environment.NewLine, 
					                                            "sermon_recv");
					break;
				case SerialDirection.SERIAL_SENT:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            str + Environment.NewLine, 
					                                            "sermon_sent");
					break;
				case SerialDirection.SERIAL_STAT:
					textview_sermon.Buffer.InsertWithTagsByName(ref iter, 
					                                            str + Environment.NewLine, 
					                                            "sermon_stat");
					break;
				}
			});
		}

		protected void OnBtSersendActivated (object sender, System.EventArgs e)
		{
		}

		protected void OnBtSersendClicked (object sender, System.EventArgs e)
		{
			SerialCom.AddCommand(0x00,"test");
			SerialCom.ProcessCommands();
		}
	}
}

