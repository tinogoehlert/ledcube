using System;

namespace cubectl
{
	[System.ComponentModel.ToolboxItem(true)]
	public partial class widget_sound : Gtk.Bin
	{
		static widget_sound _me;
		public widget_sound ()
		{
			this.Build ();
		}
		
		public static void init()
		{
			_me = new widget_sound();
		}
		
		public static widget_sound Instance(){
			return _me;	
		}
	}
}

