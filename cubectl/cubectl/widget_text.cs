using System;

namespace cubectl
{
	[System.ComponentModel.ToolboxItem(true)]
	public partial class widget_text : Gtk.Bin
	{
		public widget_text ()
		{
			this.Build ();
			this.vbox1.PackEnd(widget_sound.Instance());
			this.vbox1.ShowAll();
		}
	}
}

