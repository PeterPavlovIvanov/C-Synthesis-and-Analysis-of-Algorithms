using BetterCallTaxi.Models;
using BetterCallTaxi.Pages;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class UserHomePage : Form
    {
        private GroupBox Welcome_User;
        private Button Profile_User_Button;
        private Button Logout_User_Button;
        private Button Request_User_Button;
        private GroupBox Call_A_Taxi_Grp_Box;
        private Button Call_Taxi_Cancel_Btn;
        private Button Call_Taxi_Btn;
        private ProgressBar progressBar1;
        private TextBox Address_To_Field;
        private Label Destination_Address_Label;
        private TextBox Address_From_Field;
        private Label Address_From_Label;
        private Label waiting_label;
        private Timer timer1;
        private System.ComponentModel.IContainer components;
        private TextBox Time_Of_Order_Field;
        private Label Order_Time_Label;
        private Customer recCustomer;
        private OrderRequest recOrderRequest;

        public UserHomePage(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;
            this.Welcome_User.Text = String.Format(this.Welcome_User.Text, this.recCustomer.strName);
            this.HideCallTaxiFields();
        }

        private void HideCallTaxiFields()
        {
            this.Call_A_Taxi_Grp_Box.Hide();
            this.Time_Of_Order_Field.Hide();
            this.Order_Time_Label.Hide();
            this.progressBar1.Hide();
            this.waiting_label.Hide();
        }

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(UserHomePage));
            this.Welcome_User = new System.Windows.Forms.GroupBox();
            this.Request_User_Button = new System.Windows.Forms.Button();
            this.Logout_User_Button = new System.Windows.Forms.Button();
            this.Profile_User_Button = new System.Windows.Forms.Button();
            this.Call_A_Taxi_Grp_Box = new System.Windows.Forms.GroupBox();
            this.Time_Of_Order_Field = new System.Windows.Forms.TextBox();
            this.Order_Time_Label = new System.Windows.Forms.Label();
            this.waiting_label = new System.Windows.Forms.Label();
            this.Call_Taxi_Cancel_Btn = new System.Windows.Forms.Button();
            this.Call_Taxi_Btn = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.Address_To_Field = new System.Windows.Forms.TextBox();
            this.Destination_Address_Label = new System.Windows.Forms.Label();
            this.Address_From_Field = new System.Windows.Forms.TextBox();
            this.Address_From_Label = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.Welcome_User.SuspendLayout();
            this.Call_A_Taxi_Grp_Box.SuspendLayout();
            this.SuspendLayout();
            // 
            // Welcome_User
            // 
            this.Welcome_User.BackColor = System.Drawing.Color.Transparent;
            this.Welcome_User.Controls.Add(this.Request_User_Button);
            this.Welcome_User.Controls.Add(this.Logout_User_Button);
            this.Welcome_User.Controls.Add(this.Profile_User_Button);
            this.Welcome_User.Location = new System.Drawing.Point(13, 13);
            this.Welcome_User.Name = "Welcome_User";
            this.Welcome_User.Size = new System.Drawing.Size(183, 155);
            this.Welcome_User.TabIndex = 0;
            this.Welcome_User.TabStop = false;
            this.Welcome_User.Text = "Welcome, {0}!";
            // 
            // Request_User_Button
            // 
            this.Request_User_Button.Location = new System.Drawing.Point(7, 65);
            this.Request_User_Button.Name = "Request_User_Button";
            this.Request_User_Button.Size = new System.Drawing.Size(166, 36);
            this.Request_User_Button.TabIndex = 2;
            this.Request_User_Button.Text = "Call a Taxi";
            this.Request_User_Button.UseVisualStyleBackColor = true;
            this.Request_User_Button.Click += new System.EventHandler(this.Request_User_Button_Click);
            // 
            // Logout_User_Button
            // 
            this.Logout_User_Button.Location = new System.Drawing.Point(7, 107);
            this.Logout_User_Button.Name = "Logout_User_Button";
            this.Logout_User_Button.Size = new System.Drawing.Size(166, 36);
            this.Logout_User_Button.TabIndex = 1;
            this.Logout_User_Button.Text = "Logout";
            this.Logout_User_Button.UseVisualStyleBackColor = true;
            this.Logout_User_Button.Click += new System.EventHandler(this.Logout_User_Button_Click);
            // 
            // Profile_User_Button
            // 
            this.Profile_User_Button.Location = new System.Drawing.Point(7, 22);
            this.Profile_User_Button.Name = "Profile_User_Button";
            this.Profile_User_Button.Size = new System.Drawing.Size(166, 36);
            this.Profile_User_Button.TabIndex = 0;
            this.Profile_User_Button.Text = "Profile";
            this.Profile_User_Button.UseVisualStyleBackColor = true;
            this.Profile_User_Button.Click += new System.EventHandler(this.Profile_User_Button_Click);
            // 
            // Call_A_Taxi_Grp_Box
            // 
            this.Call_A_Taxi_Grp_Box.BackColor = System.Drawing.SystemColors.ControlLight;
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Time_Of_Order_Field);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Order_Time_Label);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.waiting_label);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Call_Taxi_Cancel_Btn);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Call_Taxi_Btn);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.progressBar1);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Address_To_Field);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Destination_Address_Label);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Address_From_Field);
            this.Call_A_Taxi_Grp_Box.Controls.Add(this.Address_From_Label);
            this.Call_A_Taxi_Grp_Box.Location = new System.Drawing.Point(544, 407);
            this.Call_A_Taxi_Grp_Box.Name = "Call_A_Taxi_Grp_Box";
            this.Call_A_Taxi_Grp_Box.Size = new System.Drawing.Size(404, 225);
            this.Call_A_Taxi_Grp_Box.TabIndex = 1;
            this.Call_A_Taxi_Grp_Box.TabStop = false;
            this.Call_A_Taxi_Grp_Box.Text = "Call A Taxi";
            // 
            // Time_Of_Order_Field
            // 
            this.Time_Of_Order_Field.Enabled = false;
            this.Time_Of_Order_Field.Location = new System.Drawing.Point(177, 124);
            this.Time_Of_Order_Field.Name = "Time_Of_Order_Field";
            this.Time_Of_Order_Field.Size = new System.Drawing.Size(211, 22);
            this.Time_Of_Order_Field.TabIndex = 9;
            // 
            // Order_Time_Label
            // 
            this.Order_Time_Label.AutoSize = true;
            this.Order_Time_Label.Location = new System.Drawing.Point(7, 124);
            this.Order_Time_Label.Name = "Order_Time_Label";
            this.Order_Time_Label.Size = new System.Drawing.Size(100, 17);
            this.Order_Time_Label.TabIndex = 8;
            this.Order_Time_Label.Text = "Time of Order:";
            // 
            // waiting_label
            // 
            this.waiting_label.AutoSize = true;
            this.waiting_label.Location = new System.Drawing.Point(7, 158);
            this.waiting_label.Name = "waiting_label";
            this.waiting_label.Size = new System.Drawing.Size(114, 17);
            this.waiting_label.TabIndex = 7;
            this.waiting_label.Text = "Waiting for a Car";
            // 
            // Call_Taxi_Cancel_Btn
            // 
            this.Call_Taxi_Cancel_Btn.Location = new System.Drawing.Point(284, 178);
            this.Call_Taxi_Cancel_Btn.Name = "Call_Taxi_Cancel_Btn";
            this.Call_Taxi_Cancel_Btn.Size = new System.Drawing.Size(104, 31);
            this.Call_Taxi_Cancel_Btn.TabIndex = 6;
            this.Call_Taxi_Cancel_Btn.Text = "Cancel";
            this.Call_Taxi_Cancel_Btn.UseVisualStyleBackColor = true;
            this.Call_Taxi_Cancel_Btn.Click += new System.EventHandler(this.Call_Taxi_Cancel_Btn_Click);
            // 
            // Call_Taxi_Btn
            // 
            this.Call_Taxi_Btn.Location = new System.Drawing.Point(177, 178);
            this.Call_Taxi_Btn.Name = "Call_Taxi_Btn";
            this.Call_Taxi_Btn.Size = new System.Drawing.Size(104, 31);
            this.Call_Taxi_Btn.TabIndex = 5;
            this.Call_Taxi_Btn.Text = "Call";
            this.Call_Taxi_Btn.UseVisualStyleBackColor = true;
            this.Call_Taxi_Btn.Click += new System.EventHandler(this.Call_Taxi_Btn_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Cursor = System.Windows.Forms.Cursors.AppStarting;
            this.progressBar1.Location = new System.Drawing.Point(10, 178);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(82, 31);
            this.progressBar1.TabIndex = 4;
            // 
            // Address_To_Field
            // 
            this.Address_To_Field.Location = new System.Drawing.Point(177, 84);
            this.Address_To_Field.Name = "Address_To_Field";
            this.Address_To_Field.Size = new System.Drawing.Size(211, 22);
            this.Address_To_Field.TabIndex = 3;
            // 
            // Destination_Address_Label
            // 
            this.Destination_Address_Label.AutoSize = true;
            this.Destination_Address_Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Destination_Address_Label.Location = new System.Drawing.Point(6, 85);
            this.Destination_Address_Label.Name = "Destination_Address_Label";
            this.Destination_Address_Label.Size = new System.Drawing.Size(139, 17);
            this.Destination_Address_Label.TabIndex = 2;
            this.Destination_Address_Label.Text = "Destination Address:";
            // 
            // Address_From_Field
            // 
            this.Address_From_Field.Location = new System.Drawing.Point(177, 47);
            this.Address_From_Field.Name = "Address_From_Field";
            this.Address_From_Field.Size = new System.Drawing.Size(211, 22);
            this.Address_From_Field.TabIndex = 1;
            // 
            // Address_From_Label
            // 
            this.Address_From_Label.AutoSize = true;
            this.Address_From_Label.Location = new System.Drawing.Point(7, 46);
            this.Address_From_Label.Name = "Address_From_Label";
            this.Address_From_Label.Size = new System.Drawing.Size(100, 17);
            this.Address_From_Label.TabIndex = 0;
            this.Address_From_Label.Text = "Address From:";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 3;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // UserHomePage
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(960, 644);
            this.Controls.Add(this.Call_A_Taxi_Grp_Box);
            this.Controls.Add(this.Welcome_User);
            this.Name = "UserHomePage";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Welcome_User.ResumeLayout(false);
            this.Call_A_Taxi_Grp_Box.ResumeLayout(false);
            this.Call_A_Taxi_Grp_Box.PerformLayout();
            this.ResumeLayout(false);

        }

        private void Logout_User_Button_Click(object sender, EventArgs e)
        {
            LogoutPopUp oDlg = new LogoutPopUp();
            DialogResult oDlgResult = oDlg.ShowDialog();
            if (oDlgResult == DialogResult.OK)
            {
                this.DialogResult = DialogResult.Cancel;
                this.Close();
            }
        }

        private void Profile_User_Button_Click(object sender, EventArgs e)
        {
            // Крием Home страницата
            this.Hide();

            // Показваме Profile страницата
            ProfileDialog oProfileDialog = new ProfileDialog(recCustomer);
            oProfileDialog.ShowDialog();
            
            // За всеки случай ако е променян потребителят, го взимаме наново от базата
            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = 
                oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_ID, this.recCustomer.nId));

            // Записваме си го при нас
            this.recCustomer = new Customer(oSqlDataReader);
            this.Welcome_User.Text = String.Format(GlobalConstants.WELCOME_USER, this.recCustomer.strName);

            // Да не забравим да затворим след нас
            oSqlDataReader.Close();

            // Показваме обратно Home страницата
            this.Show();
        }

        private void Request_User_Button_Click(object sender, EventArgs e)
        {
            // проверяваме в базата дали има заявка от този клиент
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                String.Format(GlobalConstants.SELECT_ORDER_REQUESTS_BY_CUSTOMER, this.recCustomer.nId));
            this.recOrderRequest = new OrderRequest(oSqlDataReader);
            oSqlDataReader.Close();

            // показваме скритите полета
            this.Call_A_Taxi_Grp_Box.Show();

            if (recOrderRequest.b_Last_Operation_Status) //вече има заявка за такси от този клиент, зареждаме я в полетата
            {
                // засивяваме полетата
                this.SetCallTaxiEnabledFields(false);

                // показваме скритите полета
                this.Time_Of_Order_Field.Show();
                this.Order_Time_Label.Show();
                this.progressBar1.Show();
                this.FillCallTaxiData(recOrderRequest);
                this.waiting_label.Show();

                // пускаме таймера и показваме прогрес бара
                this.timer1.Start();
            }
            else //този клиент няма заявка за такси, позволяваме му да добави, като отсивим полетата
            {
                this.SetCallTaxiEnabledFields(true);
            }

        }

        private void FillCallTaxiData(OrderRequest recOrderRequest)
        {
            this.Address_From_Field.Text = recOrderRequest.strAddressFrom;
            this.Address_To_Field.Text = recOrderRequest.strAddressTo;
            this.Time_Of_Order_Field.Text = recOrderRequest.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT);
        }

        private void SetCallTaxiEnabledFields(bool bEnabled)
        {
            this.Call_Taxi_Btn.Enabled = bEnabled;
            this.Call_Taxi_Cancel_Btn.Enabled = bEnabled;
            this.Address_From_Field.Enabled = bEnabled;
            this.Address_To_Field.Enabled = bEnabled;
        }

        private void Call_Taxi_Btn_Click(object sender, EventArgs e)
        {
            // Взимаме адресите от диалога
            this.recOrderRequest.strAddressFrom = this.Address_From_Field.Text;
            this.recOrderRequest.strAddressTo = this.Address_To_Field.Text;

            // добавяме заявката
            DatabaseManager oDatabaseManager = new DatabaseManager();
            oDatabaseManager.ExecuteQuery(
                String.Format(GlobalConstants.INSERT_ORDER_REQUEST, this.recCustomer.nId, 
                this.recOrderRequest.strAddressFrom, this.recOrderRequest.strAddressTo)
            , true);

            // крием формата за извикване на такси
            this.Call_A_Taxi_Grp_Box.Hide();
            
            // инкрементираме брояча на клиента за направени поръчки
            oDatabaseManager.ExecuteQuery(
                String.Format(GlobalConstants.UPDATE_INCREMENT_CUSTOMER_ORDERS_MADE_BY_ID, this.recCustomer.nId)
                , true, true);
            this.recCustomer.nOrdersMade += 1;

            // даваме фийдбак на потребителя
            MessageBox.Show(String.Format(GlobalConstants.SUCCESSFULLY_CALLED_TAXI_FROM_TO
                , this.recOrderRequest.strAddressFrom, this.recOrderRequest.strAddressTo));
        }

        private void Call_Taxi_Cancel_Btn_Click(object sender, EventArgs e)
        {
            this.Address_From_Field.Text = "";
            this.Address_To_Field.Text = "";
            this.HideCallTaxiFields();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.progressBar1.Increment(1);
            if (this.progressBar1.Value > 99)
                this.progressBar1.Value = 0;
        }
    }
}
