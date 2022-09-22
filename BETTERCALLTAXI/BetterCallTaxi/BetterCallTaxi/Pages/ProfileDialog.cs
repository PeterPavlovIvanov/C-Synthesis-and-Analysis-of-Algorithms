using BetterCallTaxi.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi.Pages
{
    class ProfileDialog : Form
    {
        private GroupBox Profile_Grp_Box;
        private TextBox Ucn_Profile_Field;
        private Label Ucn_Profile;
        private Label Full_Name_Profile;
        private TextBox Full_Name_Profile_Field;
        private TextBox Username_Profile_Field;
        private Label Username_Profile;
        private TextBox Orders_Made_Profile_Field;
        private Label Orders_Made_Profile;
        private GroupBox Driver_Profile_Grp_Box;
        private TextBox Driver_Profile_Money_Made_Field;
        private Label Driver_Profile_Money_Made;
        private TextBox Driver_Profile_Completed_Orders_Field;
        private Label Driver_Profile_Complete_Orders;
        private RadioButton Driver_Profile_Busy;
        private RadioButton Driver_Profile_Available;
        private Customer recCustomer;
        private GroupBox Profile_Actions_Grp_Box;
        private Button Edit_Profile_Button;
        private Button Change_Password_Profile_Button;
        private Button Profile_Home_Button;
        private Button Profile_Cancel_Button;
        private Button Profile_Save_Button;
        private GroupBox Profile_Car_Info_Grp_Box;
        private CheckBox Prof_Car_Lugage_Chck;
        private TextBox Prof_Car_Seats_Field;
        private Label Prof_Car_Seats;
        private ComboBox Prof_Car_Manufacturer_Cmb;
        private Label Prof_Car_Manufacturer;
        private TextBox Prof_Car_Reg_Nom_Field;
        private Label Prof_Car_Reg_Nom;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private Driver recDriver;

        public ProfileDialog(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;
            this.FillBasicData();
            this.SetControlsState();

            switch (recCustomer.nRoleId)
            {
                case (int)Customer.Roles.RoleDriver:
                    AccessDriver();
                    FillManufacturersCombo();
                    FillDriverData();

                    this.Profile_Car_Info_Grp_Box.Show();
                    this.Driver_Profile_Grp_Box.Show();
                    this.Profile_Grp_Box.Size = new System.Drawing.Size(213, 395);
                    break;
                case (int)Customer.Roles.RoleAdministrator:
                    
                case (int)Customer.Roles.RoleUser:
                    this.Driver_Profile_Grp_Box.Hide();
                    this.Profile_Car_Info_Grp_Box.Hide();
                    this.Profile_Grp_Box.Size = new System.Drawing.Size(213, 225);
                    break;
            }
        }

        private void FillManufacturersCombo()
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ALL_MANUFACTURERS);
            ManufacturersReader oManufacturersReader = new ManufacturersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.Prof_Car_Manufacturer_Cmb.DataSource = oManufacturersReader.oManufacturersList;
            this.Prof_Car_Manufacturer_Cmb.DisplayMember = "strName";
            this.Prof_Car_Manufacturer_Cmb.ValueMember = "nId";
        }

        private void SetControlsState(bool bEnabled = false)
        {
            this.Full_Name_Profile_Field.Enabled = bEnabled;
            this.Ucn_Profile_Field.Enabled = false;                     // служебно поле - не би следвало да може да си сменяме ЕГН
            this.Username_Profile_Field.Enabled = bEnabled;
            this.Orders_Made_Profile_Field.Enabled = false;             // служебно поле
            this.Driver_Profile_Money_Made_Field.Enabled = false;       // служебно поле
            this.Driver_Profile_Completed_Orders_Field.Enabled = false; // служебно поле
            this.Driver_Profile_Busy.Enabled = false;                   // служебно поле
            this.Driver_Profile_Available.Enabled = false;              // служебно поле

            if (bEnabled)
            {
                if (this.recCustomer.nRoleId == (int)Customer.Roles.RoleDriver)
                {
                    this.Profile_Save_Button.Location = new System.Drawing.Point(13, 420);
                    this.Profile_Cancel_Button.Location = new System.Drawing.Point(127, 420);
                }
                else
                {
                    this.Profile_Save_Button.Location = new System.Drawing.Point(13, 250);
                    this.Profile_Cancel_Button.Location = new System.Drawing.Point(127, 250);
                }


                this.Profile_Save_Button.Show();
                this.Profile_Cancel_Button.Show();
            }
            else
            {
                if (this.recCustomer.nRoleId == (int)Customer.Roles.RoleUser)
                {
                    this.Profile_Save_Button.Location = new System.Drawing.Point(13, 225);
                    this.Profile_Cancel_Button.Location = new System.Drawing.Point(127, 250);
                }
                else
                {
                    this.Profile_Save_Button.Location = new System.Drawing.Point(13, 395);
                    this.Profile_Cancel_Button.Location = new System.Drawing.Point(127, 395);
                }

                this.Profile_Save_Button.Hide();
                this.Profile_Cancel_Button.Hide();
            }

        }
        
        private void AccessDriver()
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader =
                oDatabaseManager.ExecuteQuery(String.Format(
                    GlobalConstants.SELECT_DRIVER_BY_CUSTOMER_ID, this.recCustomer.nId));

            this.recDriver = new Driver(oSqlDataReader);
            oSqlDataReader.Close();
        }

        private void FillDriverData()
        {
            this.FillCarData();

            this.Driver_Profile_Completed_Orders_Field.Text = this.recDriver.nCompletedOrders.ToString();
            this.Driver_Profile_Money_Made_Field.Text = this.recDriver.dMoneyMade.ToString();
            this.Driver_Profile_Available.Checked = this.recDriver.bStatus;
            this.Driver_Profile_Busy.Checked = !(this.recDriver.bStatus);
        }

        private void FillCarData()
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                String.Format(GlobalConstants.SELECT_CAR_BY_DRIVER_ID, this.recDriver.nId));
            Car recCar = new Car(oSqlDataReader);
            oSqlDataReader.Close();

            this.Prof_Car_Reg_Nom_Field.Text = recCar.strRegNomer;
            this.Prof_Car_Manufacturer_Cmb.SelectedValue = recCar.nManufacturerId;
            this.Prof_Car_Seats_Field.Text = recCar.bySeats.ToString();
            this.Prof_Car_Lugage_Chck.Checked = recCar.bLugage;
        }

        private void FillBasicData()
        {
            this.Full_Name_Profile_Field.Text = this.recCustomer.strName;
            this.Ucn_Profile_Field.Text = this.recCustomer.strUcn;
            this.Orders_Made_Profile_Field.Text = this.recCustomer.nOrdersMade.ToString();
            this.Username_Profile_Field.Text = this.recCustomer.strUsername;
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ProfileDialog));
            this.Profile_Grp_Box = new System.Windows.Forms.GroupBox();
            this.Driver_Profile_Grp_Box = new System.Windows.Forms.GroupBox();
            if(this.Driver_Profile_Money_Made_Field == null)
                this.Driver_Profile_Money_Made_Field = new System.Windows.Forms.TextBox();
            this.Driver_Profile_Money_Made = new System.Windows.Forms.Label();
            if(this.Driver_Profile_Completed_Orders_Field == null)
                this.Driver_Profile_Completed_Orders_Field = new System.Windows.Forms.TextBox();
            this.Driver_Profile_Complete_Orders = new System.Windows.Forms.Label();
            this.Driver_Profile_Busy = new System.Windows.Forms.RadioButton();
            this.Driver_Profile_Available = new System.Windows.Forms.RadioButton();
            if(this.Orders_Made_Profile_Field == null)
                this.Orders_Made_Profile_Field = new System.Windows.Forms.TextBox();
            this.Orders_Made_Profile = new System.Windows.Forms.Label();
            if(this.Username_Profile_Field == null)
                this.Username_Profile_Field = new System.Windows.Forms.TextBox();
            this.Username_Profile = new System.Windows.Forms.Label();
            if(this.Ucn_Profile_Field == null)
                this.Ucn_Profile_Field = new System.Windows.Forms.TextBox();
            this.Ucn_Profile = new System.Windows.Forms.Label();
            this.Full_Name_Profile = new System.Windows.Forms.Label();
            if(this.Full_Name_Profile_Field == null)
                this.Full_Name_Profile_Field = new System.Windows.Forms.TextBox();
            this.Profile_Cancel_Button = new System.Windows.Forms.Button();
            this.Profile_Save_Button = new System.Windows.Forms.Button();
            this.Profile_Actions_Grp_Box = new System.Windows.Forms.GroupBox();
            this.Profile_Home_Button = new System.Windows.Forms.Button();
            this.Change_Password_Profile_Button = new System.Windows.Forms.Button();
            this.Edit_Profile_Button = new System.Windows.Forms.Button();
            this.Profile_Car_Info_Grp_Box = new System.Windows.Forms.GroupBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.Prof_Car_Reg_Nom = new System.Windows.Forms.Label();
            if(this.Prof_Car_Reg_Nom_Field == null)
                this.Prof_Car_Reg_Nom_Field = new System.Windows.Forms.TextBox();
            this.Prof_Car_Manufacturer = new System.Windows.Forms.Label();
            if(this.Prof_Car_Manufacturer_Cmb == null)
                this.Prof_Car_Manufacturer_Cmb = new System.Windows.Forms.ComboBox();
            this.Prof_Car_Seats = new System.Windows.Forms.Label();
            if(this.Prof_Car_Seats_Field == null)
                this.Prof_Car_Seats_Field = new System.Windows.Forms.TextBox();
            this.Prof_Car_Lugage_Chck = new System.Windows.Forms.CheckBox();
            this.Profile_Grp_Box.SuspendLayout();
            this.Driver_Profile_Grp_Box.SuspendLayout();
            this.Profile_Actions_Grp_Box.SuspendLayout();
            this.Profile_Car_Info_Grp_Box.SuspendLayout();
            this.SuspendLayout();
            // 
            // Profile_Grp_Box
            // 
            this.Profile_Grp_Box.BackColor = System.Drawing.Color.Transparent;
            this.Profile_Grp_Box.Controls.Add(this.Driver_Profile_Grp_Box);
            this.Profile_Grp_Box.Controls.Add(this.Orders_Made_Profile_Field);
            this.Profile_Grp_Box.Controls.Add(this.Orders_Made_Profile);
            this.Profile_Grp_Box.Controls.Add(this.Username_Profile_Field);
            this.Profile_Grp_Box.Controls.Add(this.Username_Profile);
            this.Profile_Grp_Box.Controls.Add(this.Ucn_Profile_Field);
            this.Profile_Grp_Box.Controls.Add(this.Ucn_Profile);
            this.Profile_Grp_Box.Controls.Add(this.Full_Name_Profile);
            this.Profile_Grp_Box.Controls.Add(this.Full_Name_Profile_Field);
            this.Profile_Grp_Box.Location = new System.Drawing.Point(13, 13);
            this.Profile_Grp_Box.Name = "Profile_Grp_Box";
            this.Profile_Grp_Box.Size = new System.Drawing.Size(213, 397);
            this.Profile_Grp_Box.TabIndex = 0;
            this.Profile_Grp_Box.TabStop = false;
            this.Profile_Grp_Box.Text = "Profile";
            // 
            // Driver_Profile_Grp_Box
            // 
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Money_Made_Field);
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Money_Made);
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Completed_Orders_Field);
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Complete_Orders);
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Busy);
            this.Driver_Profile_Grp_Box.Controls.Add(this.Driver_Profile_Available);
            this.Driver_Profile_Grp_Box.Location = new System.Drawing.Point(7, 224);
            this.Driver_Profile_Grp_Box.Name = "Driver_Profile_Grp_Box";
            this.Driver_Profile_Grp_Box.Size = new System.Drawing.Size(198, 160);
            this.Driver_Profile_Grp_Box.TabIndex = 8;
            this.Driver_Profile_Grp_Box.TabStop = false;
            this.Driver_Profile_Grp_Box.Text = "Driver Info";
            // 
            // Driver_Profile_Money_Made_Field
            // 
            this.Driver_Profile_Money_Made_Field.Location = new System.Drawing.Point(125, 117);
            this.Driver_Profile_Money_Made_Field.Name = "Driver_Profile_Money_Made_Field";
            this.Driver_Profile_Money_Made_Field.Size = new System.Drawing.Size(67, 22);
            this.Driver_Profile_Money_Made_Field.TabIndex = 5;
            // 
            // Driver_Profile_Money_Made
            // 
            this.Driver_Profile_Money_Made.AutoSize = true;
            this.Driver_Profile_Money_Made.Location = new System.Drawing.Point(0, 120);
            this.Driver_Profile_Money_Made.Name = "Driver_Profile_Money_Made";
            this.Driver_Profile_Money_Made.Size = new System.Drawing.Size(129, 17);
            this.Driver_Profile_Money_Made.TabIndex = 4;
            this.Driver_Profile_Money_Made.Text = "Total money made:";
            // 
            // Driver_Profile_Completed_Orders_Field
            // 
            this.Driver_Profile_Completed_Orders_Field.Location = new System.Drawing.Point(125, 80);
            this.Driver_Profile_Completed_Orders_Field.Name = "Driver_Profile_Completed_Orders_Field";
            this.Driver_Profile_Completed_Orders_Field.Size = new System.Drawing.Size(67, 22);
            this.Driver_Profile_Completed_Orders_Field.TabIndex = 3;
            // 
            // Driver_Profile_Complete_Orders
            // 
            this.Driver_Profile_Complete_Orders.AutoSize = true;
            this.Driver_Profile_Complete_Orders.Location = new System.Drawing.Point(-1, 84);
            this.Driver_Profile_Complete_Orders.Name = "Driver_Profile_Complete_Orders";
            this.Driver_Profile_Complete_Orders.Size = new System.Drawing.Size(124, 17);
            this.Driver_Profile_Complete_Orders.TabIndex = 2;
            this.Driver_Profile_Complete_Orders.Text = "Completed orders:";
            // 
            // Driver_Profile_Busy
            // 
            this.Driver_Profile_Busy.AutoSize = true;
            this.Driver_Profile_Busy.Location = new System.Drawing.Point(7, 50);
            this.Driver_Profile_Busy.Name = "Driver_Profile_Busy";
            this.Driver_Profile_Busy.Size = new System.Drawing.Size(60, 21);
            this.Driver_Profile_Busy.TabIndex = 1;
            this.Driver_Profile_Busy.TabStop = true;
            this.Driver_Profile_Busy.Text = "Busy";
            this.Driver_Profile_Busy.UseVisualStyleBackColor = true;
            this.Driver_Profile_Busy.CheckedChanged += new System.EventHandler(this.Driver_Profile_Busy_CheckedChanged);
            // 
            // Driver_Profile_Available
            // 
            this.Driver_Profile_Available.AutoSize = true;
            this.Driver_Profile_Available.Location = new System.Drawing.Point(7, 22);
            this.Driver_Profile_Available.Name = "Driver_Profile_Available";
            this.Driver_Profile_Available.Size = new System.Drawing.Size(86, 21);
            this.Driver_Profile_Available.TabIndex = 0;
            this.Driver_Profile_Available.TabStop = true;
            this.Driver_Profile_Available.Text = "Available";
            this.Driver_Profile_Available.UseVisualStyleBackColor = true;
            this.Driver_Profile_Available.CheckedChanged += new System.EventHandler(this.Driver_Profile_Available_CheckedChanged);
            // 
            // Orders_Made_Profile_Field
            // 
            this.Orders_Made_Profile_Field.Location = new System.Drawing.Point(132, 186);
            this.Orders_Made_Profile_Field.Name = "Orders_Made_Profile_Field";
            this.Orders_Made_Profile_Field.Size = new System.Drawing.Size(73, 22);
            this.Orders_Made_Profile_Field.TabIndex = 7;
            // 
            // Orders_Made_Profile
            // 
            this.Orders_Made_Profile.AutoSize = true;
            this.Orders_Made_Profile.Location = new System.Drawing.Point(6, 189);
            this.Orders_Made_Profile.Name = "Orders_Made_Profile";
            this.Orders_Made_Profile.Size = new System.Drawing.Size(122, 17);
            this.Orders_Made_Profile.TabIndex = 6;
            this.Orders_Made_Profile.Text = "Total Taxis called:";
            // 
            // Username_Profile_Field
            // 
            this.Username_Profile_Field.Location = new System.Drawing.Point(6, 147);
            this.Username_Profile_Field.Name = "Username_Profile_Field";
            this.Username_Profile_Field.Size = new System.Drawing.Size(199, 22);
            this.Username_Profile_Field.TabIndex = 5;
            // 
            // Username_Profile
            // 
            this.Username_Profile.AutoSize = true;
            this.Username_Profile.Location = new System.Drawing.Point(3, 127);
            this.Username_Profile.Name = "Username_Profile";
            this.Username_Profile.Size = new System.Drawing.Size(77, 17);
            this.Username_Profile.TabIndex = 4;
            this.Username_Profile.Text = "Username:";
            // 
            // Ucn_Profile_Field
            // 
            this.Ucn_Profile_Field.Location = new System.Drawing.Point(6, 98);
            this.Ucn_Profile_Field.Name = "Ucn_Profile_Field";
            this.Ucn_Profile_Field.Size = new System.Drawing.Size(199, 22);
            this.Ucn_Profile_Field.TabIndex = 3;
            // 
            // Ucn_Profile
            // 
            this.Ucn_Profile.AutoSize = true;
            this.Ucn_Profile.Location = new System.Drawing.Point(3, 78);
            this.Ucn_Profile.Name = "Ucn_Profile";
            this.Ucn_Profile.Size = new System.Drawing.Size(41, 17);
            this.Ucn_Profile.TabIndex = 2;
            this.Ucn_Profile.Text = "UCN:";
            // 
            // Full_Name_Profile
            // 
            this.Full_Name_Profile.AutoSize = true;
            this.Full_Name_Profile.Location = new System.Drawing.Point(3, 28);
            this.Full_Name_Profile.Name = "Full_Name_Profile";
            this.Full_Name_Profile.Size = new System.Drawing.Size(75, 17);
            this.Full_Name_Profile.TabIndex = 1;
            this.Full_Name_Profile.Text = "Full Name:";
            // 
            // Full_Name_Profile_Field
            // 
            this.Full_Name_Profile_Field.Location = new System.Drawing.Point(6, 48);
            this.Full_Name_Profile_Field.Name = "Full_Name_Profile_Field";
            this.Full_Name_Profile_Field.Size = new System.Drawing.Size(199, 22);
            this.Full_Name_Profile_Field.TabIndex = 0;
            // 
            // Profile_Cancel_Button
            // 
            this.Profile_Cancel_Button.Location = new System.Drawing.Point(127, 416);
            this.Profile_Cancel_Button.Name = "Profile_Cancel_Button";
            this.Profile_Cancel_Button.Size = new System.Drawing.Size(99, 35);
            this.Profile_Cancel_Button.TabIndex = 9;
            this.Profile_Cancel_Button.Text = "Cancel";
            this.Profile_Cancel_Button.UseVisualStyleBackColor = true;
            this.Profile_Cancel_Button.Click += new System.EventHandler(this.Profile_Cancel_Button_Click);
            // 
            // Profile_Save_Button
            // 
            this.Profile_Save_Button.Location = new System.Drawing.Point(13, 416);
            this.Profile_Save_Button.Name = "Profile_Save_Button";
            this.Profile_Save_Button.Size = new System.Drawing.Size(100, 35);
            this.Profile_Save_Button.TabIndex = 2;
            this.Profile_Save_Button.Text = "Save";
            this.Profile_Save_Button.UseVisualStyleBackColor = true;
            this.Profile_Save_Button.Click += new System.EventHandler(this.Profile_Save_Button_Click);
            // 
            // Profile_Actions_Grp_Box
            // 
            this.Profile_Actions_Grp_Box.BackColor = System.Drawing.Color.Transparent;
            this.Profile_Actions_Grp_Box.Controls.Add(this.Profile_Home_Button);
            this.Profile_Actions_Grp_Box.Controls.Add(this.Change_Password_Profile_Button);
            this.Profile_Actions_Grp_Box.Controls.Add(this.Edit_Profile_Button);
            this.Profile_Actions_Grp_Box.Location = new System.Drawing.Point(748, 13);
            this.Profile_Actions_Grp_Box.Name = "Profile_Actions_Grp_Box";
            this.Profile_Actions_Grp_Box.Size = new System.Drawing.Size(200, 144);
            this.Profile_Actions_Grp_Box.TabIndex = 1;
            this.Profile_Actions_Grp_Box.TabStop = false;
            this.Profile_Actions_Grp_Box.Text = "Actions";
            // 
            // Profile_Home_Button
            // 
            this.Profile_Home_Button.Location = new System.Drawing.Point(7, 102);
            this.Profile_Home_Button.Name = "Profile_Home_Button";
            this.Profile_Home_Button.Size = new System.Drawing.Size(187, 33);
            this.Profile_Home_Button.TabIndex = 2;
            this.Profile_Home_Button.Text = "Home";
            this.Profile_Home_Button.UseVisualStyleBackColor = true;
            this.Profile_Home_Button.Click += new System.EventHandler(this.Profile_Home_Button_Click);
            // 
            // Change_Password_Profile_Button
            // 
            this.Change_Password_Profile_Button.Location = new System.Drawing.Point(7, 62);
            this.Change_Password_Profile_Button.Name = "Change_Password_Profile_Button";
            this.Change_Password_Profile_Button.Size = new System.Drawing.Size(187, 33);
            this.Change_Password_Profile_Button.TabIndex = 1;
            this.Change_Password_Profile_Button.Text = "Change Password";
            this.Change_Password_Profile_Button.UseVisualStyleBackColor = true;
            // 
            // Edit_Profile_Button
            // 
            this.Edit_Profile_Button.Location = new System.Drawing.Point(7, 22);
            this.Edit_Profile_Button.Name = "Edit_Profile_Button";
            this.Edit_Profile_Button.Size = new System.Drawing.Size(187, 33);
            this.Edit_Profile_Button.TabIndex = 0;
            this.Edit_Profile_Button.Text = "Edit Profile";
            this.Edit_Profile_Button.UseVisualStyleBackColor = true;
            this.Edit_Profile_Button.Click += new System.EventHandler(this.Edit_Profile_Button_Click);
            // 
            // Profile_Car_Info_Grp_Box
            // 
            this.Profile_Car_Info_Grp_Box.BackColor = System.Drawing.Color.Transparent;
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Lugage_Chck);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Seats_Field);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Seats);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Manufacturer_Cmb);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Manufacturer);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Reg_Nom_Field);
            this.Profile_Car_Info_Grp_Box.Controls.Add(this.Prof_Car_Reg_Nom);
            this.Profile_Car_Info_Grp_Box.Location = new System.Drawing.Point(748, 163);
            this.Profile_Car_Info_Grp_Box.Name = "Profile_Car_Info_Grp_Box";
            this.Profile_Car_Info_Grp_Box.Size = new System.Drawing.Size(200, 234);
            this.Profile_Car_Info_Grp_Box.TabIndex = 10;
            this.Profile_Car_Info_Grp_Box.TabStop = false;
            this.Profile_Car_Info_Grp_Box.Text = "Car Info";
            // 
            // Prof_Car_Reg_Nom
            // 
            this.Prof_Car_Reg_Nom.AutoSize = true;
            this.Prof_Car_Reg_Nom.Location = new System.Drawing.Point(4, 27);
            this.Prof_Car_Reg_Nom.Name = "Prof_Car_Reg_Nom";
            this.Prof_Car_Reg_Nom.Size = new System.Drawing.Size(65, 17);
            this.Prof_Car_Reg_Nom.TabIndex = 0;
            this.Prof_Car_Reg_Nom.Text = "Serial ID:";
            // 
            // Prof_Car_Reg_Nom_Field
            // 
            this.Prof_Car_Reg_Nom_Field.Enabled = false;
            this.Prof_Car_Reg_Nom_Field.Location = new System.Drawing.Point(7, 48);
            this.Prof_Car_Reg_Nom_Field.Name = "Prof_Car_Reg_Nom_Field";
            this.Prof_Car_Reg_Nom_Field.Size = new System.Drawing.Size(187, 22);
            this.Prof_Car_Reg_Nom_Field.TabIndex = 1;
            // 
            // Prof_Car_Manufacturer
            // 
            this.Prof_Car_Manufacturer.AutoSize = true;
            this.Prof_Car_Manufacturer.Location = new System.Drawing.Point(7, 77);
            this.Prof_Car_Manufacturer.Name = "Prof_Car_Manufacturer";
            this.Prof_Car_Manufacturer.Size = new System.Drawing.Size(96, 17);
            this.Prof_Car_Manufacturer.TabIndex = 2;
            this.Prof_Car_Manufacturer.Text = "Manufacturer:";
            // 
            // Prof_Car_Manufacturer_Cmb
            // 
            this.Prof_Car_Manufacturer_Cmb.Enabled = false;
            this.Prof_Car_Manufacturer_Cmb.FormattingEnabled = true;
            this.Prof_Car_Manufacturer_Cmb.Location = new System.Drawing.Point(6, 97);
            this.Prof_Car_Manufacturer_Cmb.Name = "Prof_Car_Manufacturer_Cmb";
            this.Prof_Car_Manufacturer_Cmb.Size = new System.Drawing.Size(188, 24);
            this.Prof_Car_Manufacturer_Cmb.TabIndex = 3;
            // 
            // Prof_Car_Seats
            // 
            this.Prof_Car_Seats.AutoSize = true;
            this.Prof_Car_Seats.Location = new System.Drawing.Point(7, 150);
            this.Prof_Car_Seats.Name = "Prof_Car_Seats";
            this.Prof_Car_Seats.Size = new System.Drawing.Size(118, 17);
            this.Prof_Car_Seats.TabIndex = 4;
            this.Prof_Car_Seats.Text = "Number of Seats:";
            // 
            // Prof_Car_Seats_Field
            // 
            this.Prof_Car_Seats_Field.Enabled = false;
            this.Prof_Car_Seats_Field.Location = new System.Drawing.Point(131, 148);
            this.Prof_Car_Seats_Field.Name = "Prof_Car_Seats_Field";
            this.Prof_Car_Seats_Field.Size = new System.Drawing.Size(62, 22);
            this.Prof_Car_Seats_Field.TabIndex = 5;
            // 
            // Prof_Car_Lugage_Chck
            // 
            this.Prof_Car_Lugage_Chck.AutoSize = true;
            this.Prof_Car_Lugage_Chck.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Prof_Car_Lugage_Chck.Enabled = false;
            this.Prof_Car_Lugage_Chck.Location = new System.Drawing.Point(6, 194);
            this.Prof_Car_Lugage_Chck.Name = "Prof_Car_Lugage_Chck";
            this.Prof_Car_Lugage_Chck.Size = new System.Drawing.Size(139, 21);
            this.Prof_Car_Lugage_Chck.TabIndex = 6;
            this.Prof_Car_Lugage_Chck.Text = "Supports Lugage";
            this.Prof_Car_Lugage_Chck.UseVisualStyleBackColor = true;
            // 
            // ProfileDialog
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(960, 644);
            this.Controls.Add(this.Profile_Car_Info_Grp_Box);
            this.Controls.Add(this.Profile_Cancel_Button);
            this.Controls.Add(this.Profile_Actions_Grp_Box);
            this.Controls.Add(this.Profile_Save_Button);
            this.Controls.Add(this.Profile_Grp_Box);
            this.Name = "ProfileDialog";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Profile";
            this.Profile_Grp_Box.ResumeLayout(false);
            this.Profile_Grp_Box.PerformLayout();
            this.Driver_Profile_Grp_Box.ResumeLayout(false);
            this.Driver_Profile_Grp_Box.PerformLayout();
            this.Profile_Actions_Grp_Box.ResumeLayout(false);
            this.Profile_Car_Info_Grp_Box.ResumeLayout(false);
            this.Profile_Car_Info_Grp_Box.PerformLayout();
            this.ResumeLayout(false);

        }

        private void Driver_Profile_Available_CheckedChanged(object sender, EventArgs e)
        {
            this.Driver_Profile_Busy.Checked = !this.Driver_Profile_Available.Checked;
        }

        private void Driver_Profile_Busy_CheckedChanged(object sender, EventArgs e)
        {
            this.Driver_Profile_Available.Checked = !this.Driver_Profile_Busy.Checked;
        }

        private void Profile_Home_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        private void Edit_Profile_Button_Click(object sender, EventArgs e)
        {
            this.SetControlsState(true);
        }

        private void Profile_Cancel_Button_Click(object sender, EventArgs e)
        {
            this.SetControlsState();
            this.FillBasicData();
        }

        private void Get_Data_From_Fields()
        {
            this.recCustomer.strName = this.Full_Name_Profile_Field.Text;
            this.recCustomer.strUsername = this.Username_Profile_Field.Text;
        }


        private void Profile_Save_Button_Click(object sender, EventArgs e)
        {
            // Валидираме
            if (!InputValidator.Validate_Username(this.Username_Profile_Field.Text))
                return;

            if (!InputValidator.Validate_Full_Name(this.Full_Name_Profile_Field.Text))
                return;

            DatabaseManager oDatabaseManager = new DatabaseManager();

            // Проверяваме за вече съществуващи username-и само ако има промяна в полето
            if (this.recCustomer.strUsername != this.Username_Profile_Field.Text) 
            {
                if (!oDatabaseManager.Check_Username_Availability(this.Username_Profile_Field.Text))
                {
                    MessageBox.Show(String.Format(GlobalConstants.USERNAME_TAKEN, this.Username_Profile_Field.Text));
                    return;
                }
            }

            // Редактираме в базата
            oDatabaseManager.ExecuteQuery(String.Format(
                GlobalConstants.UPDATE_CUSTOMER_NAME_AND_USERNAME_BY_ID, this.Full_Name_Profile_Field.Text, this.Username_Profile_Field.Text, this.recCustomer.nId)
            , false, true);

            this.SetControlsState();
            this.Get_Data_From_Fields();
        }
    }
}
