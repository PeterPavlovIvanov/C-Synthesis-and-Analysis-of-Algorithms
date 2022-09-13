using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class LoginDialog : Form
    {

        private TextBox Username_Field;
        private TextBox Password_Field;
        private Label Username;
        private Label Password;
        private Button Back_Login_Button;
        private Button Login_Button;

        public LoginDialog ()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LoginDialog));

            if(this.Username_Field == null)
            { this.Username_Field = new TextBox(); }
            if (this.Password_Field == null)
            { this.Password_Field = new TextBox(); }
            this.Username = new System.Windows.Forms.Label();
            this.Password = new System.Windows.Forms.Label();
            this.Back_Login_Button = new System.Windows.Forms.Button();
            this.Login_Button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Username_Field
            // 
            this.Username_Field.Location = new System.Drawing.Point(15, 29);
            this.Username_Field.Name = "Username_Field";
            this.Username_Field.Size = new System.Drawing.Size(182, 22);
            this.Username_Field.TabIndex = 0;
            // 
            // Password_Field
            // 
            this.Password_Field.Location = new System.Drawing.Point(15, 74);
            this.Password_Field.Name = "Password_Field";
            this.Password_Field.PasswordChar = '*';
            this.Password_Field.Size = new System.Drawing.Size(182, 22);
            this.Password_Field.TabIndex = 1;
            // 
            // Login_Button
            // 
            this.Login_Button.BackColor = System.Drawing.Color.Transparent;
            this.Login_Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Login_Button.Location = new System.Drawing.Point(15, 119);
            this.Login_Button.Name = "Login_Button";
            this.Login_Button.Size = new System.Drawing.Size(89, 33);
            this.Login_Button.TabIndex = 2;
            this.Login_Button.Text = "Login";
            this.Login_Button.UseVisualStyleBackColor = false;
            this.Login_Button.Click += new System.EventHandler(this.Login_Button_Click);
            // 
            // Back_Login_Button
            // 
            this.Back_Login_Button.BackColor = System.Drawing.Color.Transparent;
            this.Back_Login_Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Back_Login_Button.Location = new System.Drawing.Point(109, 119);
            this.Back_Login_Button.Name = "Back_Login_Button";
            this.Back_Login_Button.Size = new System.Drawing.Size(89, 33);
            this.Back_Login_Button.TabIndex = 3;
            this.Back_Login_Button.Text = "Back";
            this.Back_Login_Button.UseVisualStyleBackColor = false;
            this.Back_Login_Button.Click += new System.EventHandler(this.Back_Login_Button_Click);
            // 
            // Username
            // 
            this.Username.AutoSize = true;
            this.Username.BackColor = System.Drawing.Color.Transparent;
            this.Username.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Username.ForeColor = System.Drawing.SystemColors.Desktop;
            this.Username.Location = new System.Drawing.Point(12, 9);
            this.Username.Name = "Username";
            this.Username.Size = new System.Drawing.Size(77, 17);
            this.Username.TabIndex = 4;
            this.Username.Text = "Username:";
            // 
            // Password
            // 
            this.Password.AutoSize = true;
            this.Password.BackColor = System.Drawing.Color.Transparent;
            this.Password.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Password.ForeColor = System.Drawing.SystemColors.Desktop;
            this.Password.Location = new System.Drawing.Point(12, 54);
            this.Password.Name = "Password";
            this.Password.Size = new System.Drawing.Size(73, 17);
            this.Password.TabIndex = 5;
            this.Password.Text = "Password:";
            // 
            // LoginDialog
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(959, 641);
            this.Controls.Add(this.Login_Button);
            this.Controls.Add(this.Back_Login_Button);
            this.Controls.Add(this.Password);
            this.Controls.Add(this.Username);
            this.Controls.Add(this.Password_Field);
            this.Controls.Add(this.Username_Field);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Name = "LoginDialog";
            this.Text = "Login";
            this.Load += new System.EventHandler(this.LoginDialog_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void LoginDialog_Load(object sender, EventArgs e)
        {
            InitializeComponent();
        }

        private void Back_Login_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }

        private bool Validate_Fields()
        {
            if (!InputValidator.Validate_Username(this.Username_Field.Text))
                return false;

            if (!InputValidator.Validate_Password(this.Password_Field.Text))
                return false;
            
            return true;
        }

        private bool Login_Authentication()
        {
            try
            {
                DatabaseManager oDatabaseManager = new DatabaseManager();
                if (!oDatabaseManager.LoginAuthentication(this.Username_Field.Text, this.Password_Field.Text))
                {
                    MessageBox.Show(GlobalConstants.INVALID_CREDENTIALS);
                    return false;
                }

                SqlDataReader oSqlDataReader =
                    oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_USERNAME, this.Username_Field.Text));

                Customer recCustomer = new Customer(oSqlDataReader);
                MessageBox.Show(recCustomer.ToString());
            }
            catch (Exception oException)
            {
                MessageBox.Show(oException.ToString());
                return false;
            }

            return true;
        }


        private void Login_Button_Click(object sender, EventArgs e)
        {
            if (!Validate_Fields())
                return;

            if (!Login_Authentication())
                return;
        }
    }
}
