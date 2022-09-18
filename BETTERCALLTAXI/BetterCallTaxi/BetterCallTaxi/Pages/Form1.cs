using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;

namespace BetterCallTaxi
{
    public partial class Welcome : Form
    {

        public Welcome()
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
        }

        private void Login_Click(object sender, EventArgs e)
        {
            LoginDialog oLoginDialog = new LoginDialog();
            oLoginDialog.Location = this.Location;
            DialogResult eDialogResult = oLoginDialog.ShowDialog();
            this.Hide();
            switch (eDialogResult)
            {
                case DialogResult.OK:
                    Do_Login(oLoginDialog.GetUsername());
                    break;
                case DialogResult.Cancel:
                    this.Show();
                    break;
                default:

                    break;
            }
        }

        private void Do_Login(string strUsername)
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReaderCustomer =
                oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_USERNAME, strUsername));

            Customer recCustomer = new Customer(oSqlDataReaderCustomer);
            oSqlDataReaderCustomer.Close();

            switch (recCustomer.nRoleId)
            {
                case (int)Customer.Roles.RoleAdministrator:
                    AdminHomePage oAdminHomePage = new AdminHomePage(recCustomer);
                    oAdminHomePage.ShowDialog();
                    if (oAdminHomePage.DialogResult == DialogResult.Cancel)
                    {
                        this.Show();
                    }
                    break;
                case (int)Customer.Roles.RoleDriver:
                    SqlDataReader oSqlDataReaderDriver =
                        oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_DRIVER_BY_CUSTOMER_ID, recCustomer.nId));
                    Driver recDriver = new Driver(oSqlDataReaderDriver);
                    oSqlDataReaderDriver.Close();

                    DriverHomePage oDriverHomePage = new DriverHomePage(recCustomer, recDriver);
                    oDriverHomePage.ShowDialog();
                    if (oDriverHomePage.DialogResult == DialogResult.Cancel)
                    {
                        this.Show();
                    }
                    break;
                case (int)Customer.Roles.RoleUser:
                    UserHomePage oUserHomePage = new UserHomePage(recCustomer);
                    oUserHomePage.ShowDialog();
                    if (oUserHomePage.DialogResult == DialogResult.Cancel)
                    {
                        this.Show();
                    }
                    break;
            }
        }

        private void Register_Click(object sender, EventArgs e)
        {
            RegisterDialog oRegisterDialog = new RegisterDialog();
            oRegisterDialog.Location = this.Location;
            DialogResult eDialogResult = oRegisterDialog.ShowDialog();
            this.Hide();
            switch (eDialogResult)
            {
                case DialogResult.OK:
                    Do_Register(oRegisterDialog.GetUsername());
                    break;
                case DialogResult.Cancel:
                    this.Show();
                    break;
                default:

                    break;
            }
        }

        private void Do_Register(string strUsername)
        {
            Do_Login(strUsername);
        }

        private void Welcome_Load(object sender, EventArgs e)
        {
        }

       
    }
}
