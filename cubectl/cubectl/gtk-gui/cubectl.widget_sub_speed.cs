
// This file has been generated by the GUI designer. Do not modify.
namespace cubectl
{
	public partial class widget_sub_speed
	{
		private global::Gtk.VBox vbox3;
		private global::Gtk.Label label3;
		private global::Gtk.HScale hscale1;
		
		protected virtual void Build ()
		{
			global::Stetic.Gui.Initialize (this);
			// Widget cubectl.widget_sub_speed
			global::Stetic.BinContainer.Attach (this);
			this.Name = "cubectl.widget_sub_speed";
			// Container child cubectl.widget_sub_speed.Gtk.Container+ContainerChild
			this.vbox3 = new global::Gtk.VBox ();
			this.vbox3.Name = "vbox3";
			this.vbox3.Spacing = 6;
			// Container child vbox3.Gtk.Box+BoxChild
			this.label3 = new global::Gtk.Label ();
			this.label3.Name = "label3";
			this.label3.LabelProp = global::Mono.Unix.Catalog.GetString ("Speed Control");
			this.vbox3.Add (this.label3);
			global::Gtk.Box.BoxChild w1 = ((global::Gtk.Box.BoxChild)(this.vbox3 [this.label3]));
			w1.Position = 0;
			w1.Expand = false;
			w1.Fill = false;
			// Container child vbox3.Gtk.Box+BoxChild
			this.hscale1 = new global::Gtk.HScale (null);
			this.hscale1.CanFocus = true;
			this.hscale1.Name = "hscale1";
			this.hscale1.Adjustment.Upper = 100D;
			this.hscale1.Adjustment.PageIncrement = 10D;
			this.hscale1.Adjustment.StepIncrement = 1D;
			this.hscale1.DrawValue = true;
			this.hscale1.Digits = 0;
			this.hscale1.ValuePos = ((global::Gtk.PositionType)(2));
			this.vbox3.Add (this.hscale1);
			global::Gtk.Box.BoxChild w2 = ((global::Gtk.Box.BoxChild)(this.vbox3 [this.hscale1]));
			w2.Position = 1;
			w2.Expand = false;
			w2.Fill = false;
			this.Add (this.vbox3);
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.Hide ();
		}
	}
}
