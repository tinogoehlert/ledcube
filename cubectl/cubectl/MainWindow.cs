using System;
using Gtk;

public partial class MainWindow: Gtk.Window
{	
	private Gtk.ListStore liststore_effects = new Gtk.ListStore (typeof (string), typeof(int), typeof(Gtk.Widget));
	//widgets
	private cubectl.widget_text 		w_text  = new cubectl.widget_text();
	private cubectl.widget_none  		w_none  = new cubectl.widget_none();
	private cubectl.widget_sound 		w_sound = new cubectl.widget_sound();
	private cubectl.widget_sub_speed	w_sub_speed = new cubectl.widget_sub_speed();
	
	public MainWindow (): base (Gtk.WindowType.Toplevel)
	{
		Build ();
		cubectl.widget_sound.init();
		
		cubectl.SerialCom.CubeEvent_Exception += delegate(Exception e) {
			widget_console1.printException(e);
		};
		
		this.home_treeview_effects.Model = liststore_effects;
		this.home_treeview_effects.AppendColumn("Effekte",new CellRendererText(),"text",0);
		
		//TODO: load this from xml!
		liststore_effects.AppendValues("Text",0x00, w_text);
		liststore_effects.AppendValues("Zufall",0x00,w_sub_speed);
		liststore_effects.AppendValues("schalke!",0x01,w_sub_speed);
		liststore_effects.AppendValues("smiley",0x02,w_sub_speed);
		liststore_effects.AppendValues("bounce",0x03,w_sub_speed);
		liststore_effects.AppendValues("infinite cube",0x04,w_sub_speed);      
		liststore_effects.AppendValues("Aufsteigend",0x05,w_sub_speed);
		liststore_effects.AppendValues("Herzschlag",0x06,w_sub_speed);
		
		hbox_home.PackEnd(new cubectl.widget_text());
		hbox_home.ShowAll();
		notebook1.Page = 0;
		
		widget_console1.printSerial("test recv color", cubectl.SerialDirection.SERIAL_RECV);
		widget_console1.printSerial("test sent color", cubectl.SerialDirection.SERIAL_SENT);
		widget_console1.printSerial("test stat color", cubectl.SerialDirection.SERIAL_STAT);
	}
	
	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}

	protected void OnHomeTreeviewEffectsCursorChanged (object sender, System.EventArgs e)
	{
		TreeModel model;
        TreeIter iter;

        (sender as TreeView).Selection.GetSelected(out model, out iter);

        string desc = (string)model.GetValue(iter, 0);
		int    cmd 	= (int)model.GetValue(iter, 1);
		Widget wid  = (Widget)model.GetValue(iter,2);
		
		if(wid != null){
			hbox_home.Remove(hbox_home.Children[1]);
			hbox_home.PackEnd(wid);
		}
		
		hbox_home.ShowAll();	
	}

	protected void OnSerialPortsActionActivated (object sender, System.EventArgs e)
	{
		Gtk.Action act = sender as Gtk.Action;
         // get menu item associated with the drop-down menu
         Widget[] w = act.Proxies;
         MenuItem mi = w[0] as MenuItem;
         // get the dropdown menu
         Menu menu = mi.Submenu as Menu;
         // delete the menu items already in the menu
         foreach(Widget wid in menu.Children)
         {
             wid.Destroy();
         }
		
		 if(System.IO.Ports.SerialPort.GetPortNames().Length == 0)
			menu.Add(new MenuItem("no Serial Ports found"));
		
		 foreach(string port in System.IO.Ports.SerialPort.GetPortNames()){
			if(port == cubectl.SerialCom.CurrentPort){
				menu.Add(new MenuItem(string.Format("[{0}]",port)));
			}else{
				MenuItem newitem = new MenuItem(port);
				newitem.Name = port;
				
				menu.Add(new MenuItem(port));
				menu.SelectionDone += delegate(object _sender, EventArgs _e) {
					MenuItem sel = (MenuItem)((Menu)_sender).Active;
					cubectl.SerialCom.CurrentPort = ((Label)sel.Child).Text;
				};
			}
		 }
		 menu.ShowAll();
	}
}
