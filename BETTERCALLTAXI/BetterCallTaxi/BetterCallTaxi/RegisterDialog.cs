using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class RegisterDialog : Form
    {
        private Label Username_Reg;
        private TextBox Password_Reg_Field;
        private Label Password_Reg;
        private TextBox R_Password_Reg_Field;
        private Label R_Password_Reg;
        private TextBox Name_Reg_Field;
        private Label Full_Name_Reg;
        private TextBox Ucn_Reg_Field;
        private Label Ucn_Reg;
        private Button Register_Button;
        private Button Back_Reg_Button;
        private TextBox Username_Reg_Field;

        public RegisterDialog()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(RegisterDialog));
            this.Username_Reg_Field = new System.Windows.Forms.TextBox();
            this.Username_Reg = new System.Windows.Forms.Label();
            this.Password_Reg_Field = new System.Windows.Forms.TextBox();
            this.Password_Reg = new System.Windows.Forms.Label();
            this.R_Password_Reg_Field = new System.Windows.Forms.TextBox();
            this.R_Password_Reg = new System.Windows.Forms.Label();
            this.Name_Reg_Field = new System.Windows.Forms.TextBox();
            this.Full_Name_Reg = new System.Windows.Forms.Label();
            this.Ucn_Reg_Field = new System.Windows.Forms.TextBox();
            this.Ucn_Reg = new System.Windows.Forms.Label();
            this.Register_Button = new System.Windows.Forms.Button();
            this.Back_Reg_Button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Username_Reg_Field
            // 
            this.Username_Reg_Field.Location = new System.Drawing.Point(15, 29);
            this.Username_Reg_Field.Name = "Username_Reg_Field";
            this.Username_Reg_Field.Size = new System.Drawing.Size(182, 22);
            this.Username_Reg_Field.TabIndex = 0;
            // 
            // Username_Reg
            // 
            this.Username_Reg.AutoSize = true;
            this.Username_Reg.BackColor = System.Drawing.Color.Transparent;
            this.Username_Reg.ForeColor = System.Drawing.Color.Black;
            this.Username_Reg.Location = new System.Drawing.Point(12, 9);
            this.Username_Reg.Name = "Username_Reg";
            this.Username_Reg.Size = new System.Drawing.Size(77, 17);
            this.Username_Reg.TabIndex = 1;
            this.Username_Reg.Text = "Username:";
            // 
            // Password_Reg_Field
            // 
            this.Password_Reg_Field.ForeColor = System.Drawing.SystemColors.WindowText;
            this.Password_Reg_Field.Location = new System.Drawing.Point(15, 74);
            this.Password_Reg_Field.Name = "Password_Reg_Field";
            this.Password_Reg_Field.Size = new System.Drawing.Size(183, 22);
            this.Password_Reg_Field.TabIndex = 2;
            this.Password_Reg_Field.PasswordChar = '*';
            // 
            // Password_Reg
            // 
            this.Password_Reg.AutoSize = true;
            this.Password_Reg.BackColor = System.Drawing.Color.Transparent;
            this.Password_Reg.Location = new System.Drawing.Point(12, 54);
            this.Password_Reg.Name = "Password_Reg";
            this.Password_Reg.Size = new System.Drawing.Size(73, 17);
            this.Password_Reg.TabIndex = 3;
            this.Password_Reg.Text = "Password:";
            // 
            // R_Password_Reg_Field
            // 
            this.R_Password_Reg_Field.Location = new System.Drawing.Point(15, 119);
            this.R_Password_Reg_Field.Name = "R_Password_Reg_Field";
            this.R_Password_Reg_Field.Size = new System.Drawing.Size(183, 22);
            this.R_Password_Reg_Field.TabIndex = 4;
            this.Password_Reg_Field.PasswordChar = '*';
            // 
            // R_Password_Reg
            // 
            this.R_Password_Reg.AutoSize = true;
            this.R_Password_Reg.BackColor = System.Drawing.Color.Transparent;
            this.R_Password_Reg.Location = new System.Drawing.Point(12, 99);
            this.R_Password_Reg.Name = "R_Password_Reg";
            this.R_Password_Reg.Size = new System.Drawing.Size(123, 17);
            this.R_Password_Reg.TabIndex = 5;
            this.R_Password_Reg.Text = "Repeat Password:";
            // 
            // Name_Reg_Field
            // 
            this.Name_Reg_Field.Location = new System.Drawing.Point(15, 164);
            this.Name_Reg_Field.Name = "Name_Reg_Field";
            this.Name_Reg_Field.Size = new System.Drawing.Size(182, 22);
            this.Name_Reg_Field.TabIndex = 6;
            // 
            // Full_Name_Reg
            // 
            this.Full_Name_Reg.AutoSize = true;
            this.Full_Name_Reg.BackColor = System.Drawing.Color.Transparent;
            this.Full_Name_Reg.Location = new System.Drawing.Point(12, 144);
            this.Full_Name_Reg.Name = "Full_Name_Reg";
            this.Full_Name_Reg.Size = new System.Drawing.Size(75, 17);
            this.Full_Name_Reg.TabIndex = 7;
            this.Full_Name_Reg.Text = "Full Name:";
            // 
            // Ucn_Reg_Field
            // 
            this.Ucn_Reg_Field.Location = new System.Drawing.Point(15, 209);
            this.Ucn_Reg_Field.Name = "Ucn_Reg_Field";
            this.Ucn_Reg_Field.Size = new System.Drawing.Size(182, 22);
            this.Ucn_Reg_Field.TabIndex = 8;
            // 
            // Ucn_Reg
            // 
            this.Ucn_Reg.AutoSize = true;
            this.Ucn_Reg.BackColor = System.Drawing.Color.Transparent;
            this.Ucn_Reg.Location = new System.Drawing.Point(12, 189);
            this.Ucn_Reg.Name = "Ucn_Reg";
            this.Ucn_Reg.Size = new System.Drawing.Size(41, 17);
            this.Ucn_Reg.TabIndex = 9;
            this.Ucn_Reg.Text = "UCN:";
            // 
            // Register_Button
            // 
            this.Register_Button.Location = new System.Drawing.Point(15, 254);
            this.Register_Button.Name = "Register_Button";
            this.Register_Button.Size = new System.Drawing.Size(89, 33);
            this.Register_Button.TabIndex = 10;
            this.Register_Button.Text = "Register";
            this.Register_Button.UseVisualStyleBackColor = true;
            this.Register_Button.Click += new System.EventHandler(this.Register_Button_Click);
            // 
            // Back_Reg_Button
            // 
            this.Back_Reg_Button.Location = new System.Drawing.Point(109, 254);
            this.Back_Reg_Button.Name = "Back_Reg_Button";
            this.Back_Reg_Button.Size = new System.Drawing.Size(89, 33);
            this.Back_Reg_Button.TabIndex = 11;
            this.Back_Reg_Button.Text = "Back";
            this.Back_Reg_Button.UseVisualStyleBackColor = true;
            this.Back_Reg_Button.Click += new System.EventHandler(this.Back_Reg_Button_Click);
            // 
            // RegisterDialog
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(959, 644);
            this.Controls.Add(this.Back_Reg_Button);
            this.Controls.Add(this.Register_Button);
            this.Controls.Add(this.Ucn_Reg);
            this.Controls.Add(this.Ucn_Reg_Field);
            this.Controls.Add(this.Full_Name_Reg);
            this.Controls.Add(this.Name_Reg_Field);
            this.Controls.Add(this.R_Password_Reg);
            this.Controls.Add(this.R_Password_Reg_Field);
            this.Controls.Add(this.Password_Reg);
            this.Controls.Add(this.Password_Reg_Field);
            this.Controls.Add(this.Username_Reg);
            this.Controls.Add(this.Username_Reg_Field);
            this.Name = "RegisterDialog";
            this.Load += new System.EventHandler(this.RegisterDialog_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Back_Reg_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }

        private bool Validate_Fields()
        {
            if (!InputValidator.Validate_Username(this.Username_Reg_Field.Text))
                return false;

            if (!InputValidator.Validate_Password(this.Password_Reg_Field.Text))
                return false;

            if (!InputValidator.Validate_Ucn(this.Ucn_Reg_Field.Text))
                return false;

            return true;
        }

        private bool Check_Username_Availability()
        {
            try
            {
                DatabaseManager oDatabaseManager = new DatabaseManager();
                if (!oDatabaseManager.Check_Username_Availability(this.Username_Reg_Field.Text))
                {
                    MessageBox.Show(String.Format(GlobalConstants.USERNAME_TAKEN, this.Username_Reg_Field.Text));
                    return false;
                }

                SqlDataReader oSqlDataReader =
                    oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_USERNAME, this.Username_Reg_Field.Text));

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

        private void RegisterDialog_Load(object sender, EventArgs e)
        {

        }

        private void Register_Button_Click(object sender, EventArgs e)
        {
            if (!Validate_Fields())
                return;

            if (!Check_Username_Availability())
                return;


        }
    }
}
