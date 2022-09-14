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

        public Welcome()
        {
            InitializeComponent();
        }

        private void Login_Click(object sender, EventArgs e)
        {
            this.Hide();
            LoginDialog oLoginDialog = new LoginDialog();
            DialogResult eDialogResult = oLoginDialog.ShowDialog();
            switch(eDialogResult)
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
            DialogResult eDialogResult = oRegisterDialog.ShowDialog();
            switch (eDialogResult)
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
        }

       
    }
}
