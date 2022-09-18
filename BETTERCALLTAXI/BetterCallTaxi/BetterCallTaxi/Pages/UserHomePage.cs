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
        private Customer recCustomer;

        public UserHomePage(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;
            this.Welcome_User.Text = String.Format(this.Welcome_User.Text, this.recCustomer.strName);
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(UserHomePage));
            this.Welcome_User = new System.Windows.Forms.GroupBox();
            this.Request_User_Button = new System.Windows.Forms.Button();
            this.Logout_User_Button = new System.Windows.Forms.Button();
            this.Profile_User_Button = new System.Windows.Forms.Button();
            this.Welcome_User.SuspendLayout();
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
            // UserHomePage
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(960, 644);
            this.Controls.Add(this.Welcome_User);
            this.Name = "UserHomePage";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Load += new System.EventHandler(this.UserHomePage_Load);
            this.Welcome_User.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        private void Logout_User_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
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

        private void UserHomePage_Load(object sender, EventArgs e)
        {

        }
    }
}
