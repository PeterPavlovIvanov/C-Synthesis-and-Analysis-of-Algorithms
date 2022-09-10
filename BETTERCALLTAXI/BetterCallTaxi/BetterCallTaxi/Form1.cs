using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;

namespace BetterCallTaxi
{
    public partial class Welcome : Form
    {
        public const string CONNECTION_STRING = "Data Source=DESKTOP-PFQL6JD;Database=BetterCallTaxi;Integrated Security=True";

        public Welcome()
        {
            InitializeComponent();
        }

        private void Login_Click(object sender, EventArgs e)
        {
            this.Hide();
            LoginDialog oLoginDialog = new LoginDialog();
            DialogResult oDialogResult = oLoginDialog.ShowDialog();
            switch(oDialogResult)
            {
                case DialogResult.OK:

                    break;
                case DialogResult.Cancel:
                    this.Show();
                    break;
                default:

                    break;
            }
        }

        private void Register_Click(object sender, EventArgs e)
        {
            this.Hide();
            RegisterDialog oRegisterDialog = new RegisterDialog();
            DialogResult oDialogResult = oRegisterDialog.ShowDialog();
            switch (oDialogResult)
            {
                case DialogResult.OK:

                    break;
                case DialogResult.Cancel:
                    this.Show();
                    break;
                default:

                    break;
            }
        }

        private void Welcome_Load(object sender, EventArgs e)
        {
            SqlConnection oSqlConnection = new SqlConnection();
            oSqlConnection.ConnectionString = CONNECTION_STRING;
            oSqlConnection.Open();
            SqlCommand oSqlCommand = new SqlCommand("SELECT * FROM CUSTOMERS WITH(NOLOCK)", oSqlConnection);
            oSqlCommand.CommandType = CommandType.Text;
            SqlDataReader oSqlDataReader = oSqlCommand.ExecuteReader();
            string message = "";
            while (oSqlDataReader.Read())
            {
                message += oSqlDataReader.GetValue(0).ToString() + "; ";
                message += oSqlDataReader.GetValue(1).ToString() + "; ";
                message += oSqlDataReader.GetValue(2).ToString() + "; ";
                message += oSqlDataReader.GetValue(3).ToString() + "; ";
                message += oSqlDataReader.GetValue(4).ToString() + "; ";
                message += oSqlDataReader.GetValue(5).ToString() + "; ";
                message += oSqlDataReader.GetValue(6).ToString() + "; ";
                message += "\n";
            }

            oSqlConnection.Close();
            MessageBox.Show(message);
        }

       
    }
}
