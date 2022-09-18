using BetterCallTaxi.Pages;
using BetterCallTaxi.Reports.Customers;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class Admin_Home_Page : Form
    {
        private Button Orders_Before;
        private GroupBox Reports_GrpBox;
        private GroupBox Logged_In_Welcome;
        private Button Logout_Admin_Button;
        private Button Profile_Admin_Button;
        private Button Admin_Roles_Button;
        private Button Admin_Order_Requests_Button;
        private Button Admin_Manufacturers_Button;
        private Button Admin_Cars_Button;
        private Button Admin_Orders_Button;
        private Button Admin_Drivers_Button;
        private Button Admin_Customers_Button;
        Customer recCustomer;

        public Admin_Home_Page(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;    
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Admin_Home_Page));
            this.Orders_Before = new System.Windows.Forms.Button();
            this.Reports_GrpBox = new System.Windows.Forms.GroupBox();
            this.Logged_In_Welcome = new System.Windows.Forms.GroupBox();
            this.Logout_Admin_Button = new System.Windows.Forms.Button();
            this.Profile_Admin_Button = new System.Windows.Forms.Button();
            this.Admin_Customers_Button = new System.Windows.Forms.Button();
            this.Admin_Drivers_Button = new System.Windows.Forms.Button();
            this.Admin_Orders_Button = new System.Windows.Forms.Button();
            this.Admin_Cars_Button = new System.Windows.Forms.Button();
            this.Admin_Manufacturers_Button = new System.Windows.Forms.Button();
            this.Admin_Order_Requests_Button = new System.Windows.Forms.Button();
            this.Admin_Roles_Button = new System.Windows.Forms.Button();
            this.Reports_GrpBox.SuspendLayout();
            this.Logged_In_Welcome.SuspendLayout();
            this.SuspendLayout();
            // 
            // Orders_Before
            // 
            this.Orders_Before.Location = new System.Drawing.Point(6, 20);
            this.Orders_Before.Name = "Orders_Before";
            this.Orders_Before.Size = new System.Drawing.Size(166, 38);
            this.Orders_Before.TabIndex = 1;
            this.Orders_Before.Text = "Orders before date";
            this.Orders_Before.UseVisualStyleBackColor = true;
            this.Orders_Before.Click += new System.EventHandler(this.Orders_Before_Click);
            // 
            // Reports_GrpBox
            // 
            this.Reports_GrpBox.BackColor = System.Drawing.Color.Transparent;
            this.Reports_GrpBox.Controls.Add(this.Admin_Roles_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Order_Requests_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Manufacturers_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Cars_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Orders_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Drivers_Button);
            this.Reports_GrpBox.Controls.Add(this.Admin_Customers_Button);
            this.Reports_GrpBox.Controls.Add(this.Orders_Before);
            this.Reports_GrpBox.Location = new System.Drawing.Point(764, 12);
            this.Reports_GrpBox.Name = "Reports_GrpBox";
            this.Reports_GrpBox.Size = new System.Drawing.Size(182, 384);
            this.Reports_GrpBox.TabIndex = 2;
            this.Reports_GrpBox.TabStop = false;
            this.Reports_GrpBox.Text = "Reports:";
            // 
            // Logged_In_Welcome
            // 
            this.Logged_In_Welcome.BackColor = System.Drawing.Color.Transparent;
            this.Logged_In_Welcome.Controls.Add(this.Logout_Admin_Button);
            this.Logged_In_Welcome.Controls.Add(this.Profile_Admin_Button);
            this.Logged_In_Welcome.Location = new System.Drawing.Point(12, 12);
            this.Logged_In_Welcome.Name = "Logged_In_Welcome";
            this.Logged_In_Welcome.Size = new System.Drawing.Size(181, 109);
            this.Logged_In_Welcome.TabIndex = 3;
            this.Logged_In_Welcome.TabStop = false;
            this.Logged_In_Welcome.Text = "Welcome, {0}!";
            // 
            // Logout_Admin_Button
            // 
            this.Logout_Admin_Button.Location = new System.Drawing.Point(6, 62);
            this.Logout_Admin_Button.Name = "Logout_Admin_Button";
            this.Logout_Admin_Button.Size = new System.Drawing.Size(165, 36);
            this.Logout_Admin_Button.TabIndex = 1;
            this.Logout_Admin_Button.Text = "Logout";
            this.Logout_Admin_Button.UseVisualStyleBackColor = true;
            this.Logout_Admin_Button.Click += new System.EventHandler(this.Logout_Admin_Button_Click);
            // 
            // Profile_Admin_Button
            // 
            this.Profile_Admin_Button.Location = new System.Drawing.Point(6, 20);
            this.Profile_Admin_Button.Name = "Profile_Admin_Button";
            this.Profile_Admin_Button.Size = new System.Drawing.Size(166, 36);
            this.Profile_Admin_Button.TabIndex = 0;
            this.Profile_Admin_Button.Text = "Profile";
            this.Profile_Admin_Button.UseVisualStyleBackColor = true;
            this.Profile_Admin_Button.Click += new System.EventHandler(this.Profile_Admin_Button_Click);
            // 
            // Admin_Customers_Button
            // 
            this.Admin_Customers_Button.Location = new System.Drawing.Point(7, 65);
            this.Admin_Customers_Button.Name = "Admin_Customers_Button";
            this.Admin_Customers_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Customers_Button.TabIndex = 2;
            this.Admin_Customers_Button.Text = "Customers";
            this.Admin_Customers_Button.UseVisualStyleBackColor = true;
            this.Admin_Customers_Button.Click += new System.EventHandler(this.Admin_Customers_Button_Click);
            // 
            // Admin_Drivers_Button
            // 
            this.Admin_Drivers_Button.Location = new System.Drawing.Point(7, 110);
            this.Admin_Drivers_Button.Name = "Admin_Drivers_Button";
            this.Admin_Drivers_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Drivers_Button.TabIndex = 3;
            this.Admin_Drivers_Button.Text = "Drivers";
            this.Admin_Drivers_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Orders_Button
            // 
            this.Admin_Orders_Button.Location = new System.Drawing.Point(7, 155);
            this.Admin_Orders_Button.Name = "Admin_Orders_Button";
            this.Admin_Orders_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Orders_Button.TabIndex = 4;
            this.Admin_Orders_Button.Text = "Orders";
            this.Admin_Orders_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Cars_Button
            // 
            this.Admin_Cars_Button.Location = new System.Drawing.Point(7, 200);
            this.Admin_Cars_Button.Name = "Admin_Cars_Button";
            this.Admin_Cars_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Cars_Button.TabIndex = 5;
            this.Admin_Cars_Button.Text = "Cars";
            this.Admin_Cars_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Manufacturers_Button
            // 
            this.Admin_Manufacturers_Button.Location = new System.Drawing.Point(7, 245);
            this.Admin_Manufacturers_Button.Name = "Admin_Manufacturers_Button";
            this.Admin_Manufacturers_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Manufacturers_Button.TabIndex = 6;
            this.Admin_Manufacturers_Button.Text = "Manufacturers";
            this.Admin_Manufacturers_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Order_Requests_Button
            // 
            this.Admin_Order_Requests_Button.Location = new System.Drawing.Point(7, 290);
            this.Admin_Order_Requests_Button.Name = "Admin_Order_Requests_Button";
            this.Admin_Order_Requests_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Order_Requests_Button.TabIndex = 7;
            this.Admin_Order_Requests_Button.Text = "Order Requests";
            this.Admin_Order_Requests_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Roles_Button
            // 
            this.Admin_Roles_Button.Location = new System.Drawing.Point(7, 335);
            this.Admin_Roles_Button.Name = "Admin_Roles_Button";
            this.Admin_Roles_Button.Size = new System.Drawing.Size(165, 38);
            this.Admin_Roles_Button.TabIndex = 8;
            this.Admin_Roles_Button.Text = "Roles";
            this.Admin_Roles_Button.UseVisualStyleBackColor = true;
            // 
            // Admin_Home_Page
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(958, 645);
            this.Controls.Add(this.Logged_In_Welcome);
            this.Controls.Add(this.Reports_GrpBox);
            this.ForeColor = System.Drawing.Color.Black;
            this.Name = "Admin_Home_Page";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Load += new System.EventHandler(this.AdminHomePage_Load);
            this.Reports_GrpBox.ResumeLayout(false);
            this.Logged_In_Welcome.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        private void Orders_Before_Click(object sender, EventArgs e)
        {
            OrdersBeforeDateDialog oOrdBfrDateDlg = new OrdersBeforeDateDialog();
            DialogResult eDialogResult = oOrdBfrDateDlg.ShowDialog();
            switch (eDialogResult)
            {
                case DialogResult.OK:

                    break;
                case DialogResult.Cancel:

                    break;
                default:

                    break;
            }

        }

        private void AdminHomePage_Load(object sender, EventArgs e)
        {
            this.Logged_In_Welcome.Text = String.Format(Logged_In_Welcome.Text, this.recCustomer.strName);
        }

        private void Logout_Admin_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        private void Profile_Admin_Button_Click(object sender, EventArgs e)
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
            this.Logged_In_Welcome.Text = String.Format(GlobalConstants.WELCOME_USER, this.recCustomer.strName);

            // Да не забравим да затворим след нас
            oSqlDataReader.Close();

            // Показваме обратно Home страницата
            this.Show();
        }

        private void Admin_Customers_Button_Click(object sender, EventArgs e)
        {
            CustomersFilterDialog oCustomersFilterDialog = new CustomersFilterDialog();
            if (oCustomersFilterDialog.ShowDialog() == DialogResult.OK)
            {

            }
            else if (oCustomersFilterDialog.ShowDialog() == DialogResult.Cancel)
            {

            }
        }

    }
}
