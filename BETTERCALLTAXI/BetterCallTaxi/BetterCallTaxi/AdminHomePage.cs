using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class AdminHomePage : Form
    {
        private Label Logged_In_Welcome;
        private Button Orders_Before;
        private GroupBox Reports_GrpBox;
        Customer recCustomer;

        public AdminHomePage(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;    
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdminHomePage));
            this.Logged_In_Welcome = new System.Windows.Forms.Label();
            this.Orders_Before = new System.Windows.Forms.Button();
            this.Reports_GrpBox = new System.Windows.Forms.GroupBox();
            this.Reports_GrpBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // Logged_In_Welcome
            // 
            this.Logged_In_Welcome.AutoSize = true;
            this.Logged_In_Welcome.BackColor = System.Drawing.Color.Transparent;
            this.Logged_In_Welcome.Location = new System.Drawing.Point(12, 9);
            this.Logged_In_Welcome.Name = "Logged_In_Welcome";
            this.Logged_In_Welcome.Size = new System.Drawing.Size(99, 17);
            this.Logged_In_Welcome.TabIndex = 0;
            this.Logged_In_Welcome.Text = "Welcome, {0}! ";
            // 
            // Orders_Before
            // 
            this.Orders_Before.Location = new System.Drawing.Point(6, 21);
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
            this.Reports_GrpBox.Controls.Add(this.Orders_Before);
            this.Reports_GrpBox.Location = new System.Drawing.Point(764, 12);
            this.Reports_GrpBox.Name = "Reports_GrpBox";
            this.Reports_GrpBox.Size = new System.Drawing.Size(182, 326);
            this.Reports_GrpBox.TabIndex = 2;
            this.Reports_GrpBox.TabStop = false;
            this.Reports_GrpBox.Text = "Reports:";
            // 
            // AdminHomePage
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(958, 645);
            this.Controls.Add(this.Reports_GrpBox);
            this.Controls.Add(this.Logged_In_Welcome);
            this.ForeColor = System.Drawing.Color.Black;
            this.Name = "AdminHomePage";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Load += new System.EventHandler(this.AdminHomePage_Load);
            this.Reports_GrpBox.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

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

            //DatabaseManager oDatabaseManager = new DatabaseManager();
            //SqlDataReader oSqlDataReader =
            //    oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_ORDERS_BEFORE_DATE, ));

        }

        private void AdminHomePage_Load(object sender, EventArgs e)
        {
            this.Logged_In_Welcome.Text = String.Format(Logged_In_Welcome.Text, this.recCustomer.strName);
        }
    }
}
