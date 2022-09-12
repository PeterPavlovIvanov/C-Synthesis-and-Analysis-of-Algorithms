using System;
using System.Collections.Generic;
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
        private const string SELECT_CUSTOMER_BY_USERNAME = "SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = '{0}'";
        private const string INVALID_CREDENTIALS = "Invalid credentials!";

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
            this.Username_Field.TextChanged += new System.EventHandler(this.Username_Field_TextChanged);
            // 
            // Password_Field
            // 
            this.Password_Field.Location = new System.Drawing.Point(15, 74);
            this.Password_Field.Name = "Password_Field";
            this.Password_Field.PasswordChar = '*';
            this.Password_Field.Size = new System.Drawing.Size(182, 22);
            this.Password_Field.TabIndex = 1;
            this.Password_Field.TextChanged += new System.EventHandler(this.Password_Field_TextChanged);
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
            this.Username.TabIndex = 2;
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
            this.Password.TabIndex = 3;
            this.Password.Text = "Password:";
            // 
            // Back_Login_Button
            // 
            this.Back_Login_Button.BackColor = System.Drawing.Color.Transparent;
            this.Back_Login_Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Back_Login_Button.Location = new System.Drawing.Point(109, 119);
            this.Back_Login_Button.Name = "Back_Login_Button";
            this.Back_Login_Button.Size = new System.Drawing.Size(89, 33);
            this.Back_Login_Button.TabIndex = 4;
            this.Back_Login_Button.Text = "Back";
            this.Back_Login_Button.UseVisualStyleBackColor = false;
            this.Back_Login_Button.Click += new System.EventHandler(this.Back_Login_Button_Click);
            // 
            // Login_Button
            // 
            this.Login_Button.BackColor = System.Drawing.Color.Transparent;
            this.Login_Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Login_Button.Location = new System.Drawing.Point(15, 119);
            this.Login_Button.Name = "Login_Button";
            this.Login_Button.Size = new System.Drawing.Size(89, 33);
            this.Login_Button.TabIndex = 5;
            this.Login_Button.Text = "Login";
            this.Login_Button.UseVisualStyleBackColor = false;
            this.Login_Button.Click += new System.EventHandler(this.Login_Button_Click);
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

        private bool Validate_UserName()
        {
            if (this.Username_Field.Text == "")
            {
                MessageBox.Show("You must enter a username.");
                return false;
            }

            if(this.Username_Field.Text.Length < 5)
            {
                MessageBox.Show("You must enter a username longer than 4 symbols.");
                return false;
            }

            if (this.Username_Field.Text.Length > 25)
            {
                MessageBox.Show("You must enter a username shorter than 26 symbols.");
                return false;
            }

            return true;
        }

        private bool Validate_Password()
        {
            if (this.Password_Field.Text == "")
            {
                MessageBox.Show("You must enter a password.");
                return false;
            }

            if (this.Password_Field.Text.Length < 6)
            {
                MessageBox.Show("You must enter a password longer than 5 symbols.");
                return false;
            }

            if (this.Password_Field.Text.Length > 25)
            {
                MessageBox.Show("You must enter a password shorter than 26 symbols.");
                return false;
            }

            return true;
        }

        private bool Validate_Fields()
        {
            if (!Validate_UserName())
                return false;

            if (!Validate_Password())
                return false;

            return true;
        }

        private void Login_Button_Click(object sender, EventArgs e)
        {
            if (!Validate_Fields())
                return;

            try
            {
                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(String.Format(SELECT_CUSTOMER_BY_USERNAME, this.Username_Field.Text));
                Customer recCustomer = new Customer(oSqlDataReader);

                if (!recCustomer.b_Last_Operation_Status || Compare_Passwords(recCustomer.byPassword))
                {
                    MessageBox.Show(INVALID_CREDENTIALS);
                    return;
                }

                MessageBox.Show(recCustomer.ToString());
            }
            catch (Exception oException)
            {
                MessageBox.Show(oException.ToString());
            }

        }

        private bool Compare_Passwords(byte[] byPassword)
        {
            SHA256 oSHA256 = SHA256.Create();
            byte[] byUserInputPassword = oSHA256.ComputeHash(Encoding.UTF8.GetBytes(this.Password_Field.Text));

            StringBuilder oBuilderInputPassword = new StringBuilder();
            for (int i = 0; i < byUserInputPassword.Length; i++)
            {
                oBuilderInputPassword.Append(byUserInputPassword[i].ToString("x2"));
            }

            StringBuilder oBuilderDatabasePassword = new StringBuilder();
            for (int i = 0; i < byUserInputPassword.Length; i++)
            {
                oBuilderDatabasePassword.Append(byPassword[i].ToString("x2"));
            }

            MessageBox.Show("sql: " + oBuilderDatabasePassword.ToString() + "\ninput: " + oBuilderInputPassword.ToString() + "\n");
            bool bResult = oBuilderDatabasePassword.ToString().Equals(oBuilderInputPassword.ToString());
            return bResult;
        }

        private void Password_Field_TextChanged(object sender, EventArgs e)
        {

        }

        private void Username_Field_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
