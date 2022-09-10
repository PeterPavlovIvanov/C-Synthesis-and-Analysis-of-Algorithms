using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

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

        }

       
    }
}
