using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class DriverHomePage : Form
    {
        private Customer recCustomer;
        private GroupBox Welcome_Driver;
        private Button Logout_Driver_Button;
        private Button Profile_Driver_Button;
        private Driver recDriver;

        public DriverHomePage(Customer recCustomer, Driver recDriver)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;
            this.recDriver = recDriver;
            this.Welcome_Driver.Text = String.Format(this.Welcome_Driver.Text, recCustomer.strName);
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DriverHomePage));
            this.Welcome_Driver = new System.Windows.Forms.GroupBox();
            this.Profile_Driver_Button = new System.Windows.Forms.Button();
            this.Logout_Driver_Button = new System.Windows.Forms.Button();
            this.Welcome_Driver.SuspendLayout();
            this.SuspendLayout();
            // 
            // Welcome_Driver
            // 
            this.Welcome_Driver.BackColor = System.Drawing.Color.Transparent;
            this.Welcome_Driver.Controls.Add(this.Logout_Driver_Button);
            this.Welcome_Driver.Controls.Add(this.Profile_Driver_Button);
            this.Welcome_Driver.Location = new System.Drawing.Point(13, 13);
            this.Welcome_Driver.Name = "Welcome_Driver";
            this.Welcome_Driver.Size = new System.Drawing.Size(183, 114);
            this.Welcome_Driver.TabIndex = 0;
            this.Welcome_Driver.TabStop = false;
            this.Welcome_Driver.Text = "Welcome, {0}!";
            // 
            // Profile_Driver_Button
            // 
            this.Profile_Driver_Button.Location = new System.Drawing.Point(7, 22);
            this.Profile_Driver_Button.Name = "Profile_Driver_Button";
            this.Profile_Driver_Button.Size = new System.Drawing.Size(166, 36);
            this.Profile_Driver_Button.TabIndex = 0;
            this.Profile_Driver_Button.Text = "Profile";
            this.Profile_Driver_Button.UseVisualStyleBackColor = true;
            // 
            // Logout_Driver_Button
            // 
            this.Logout_Driver_Button.Location = new System.Drawing.Point(7, 65);
            this.Logout_Driver_Button.Name = "Logout_Driver_Button";
            this.Logout_Driver_Button.Size = new System.Drawing.Size(166, 36);
            this.Logout_Driver_Button.TabIndex = 1;
            this.Logout_Driver_Button.Text = "Logout";
            this.Logout_Driver_Button.UseVisualStyleBackColor = true;
            this.Logout_Driver_Button.Click += new System.EventHandler(this.Logout_Driver_Button_Click);
            // 
            // DriverHomePage
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(963, 642);
            this.Controls.Add(this.Welcome_Driver);
            this.Name = "DriverHomePage";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Welcome_Driver.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        private void Logout_Driver_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
