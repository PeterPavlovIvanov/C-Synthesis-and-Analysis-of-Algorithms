using BetterCallTaxi.Models;
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
        private CheckBox Driver_CheckBox;
        private GroupBox Reg_Car_Grp_Box;
        private CheckBox Reg_Car_Lugage_Chck;
        private ComboBox Reg_Car_Manufacturer_Cmb;
        private Label Reg_Car_Seats;
        private TextBox Reg_Car_Seats_Field;
        private TextBox Car_Reg_Nomer_Field;
        private Label Reg_Car_Nomer;
        private Label Reg_Car_Manufacturer;
        private TextBox Username_Reg_Field;

        public RegisterDialog()
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.Reg_Car_Grp_Box.Hide();
            this.LoadManufacturersCombo();
        }

        private void LoadManufacturersCombo()
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ALL_MANUFACTURERS);
            ManufacturersReader oManufacturersReader = new ManufacturersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.Reg_Car_Manufacturer_Cmb.DataSource = oManufacturersReader.oManufacturersList;
            this.Reg_Car_Manufacturer_Cmb.DisplayMember = "strName";
            this.Reg_Car_Manufacturer_Cmb.ValueMember = "nId";
        }

        public String GetUsername()
        {
            return this.Username_Reg_Field.Text;
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
            this.Driver_CheckBox = new System.Windows.Forms.CheckBox();
            this.Register_Button = new System.Windows.Forms.Button();
            this.Back_Reg_Button = new System.Windows.Forms.Button();
            this.Reg_Car_Grp_Box = new System.Windows.Forms.GroupBox();
            this.Reg_Car_Manufacturer = new System.Windows.Forms.Label();
            this.Reg_Car_Nomer = new System.Windows.Forms.Label();
            this.Car_Reg_Nomer_Field = new System.Windows.Forms.TextBox();
            this.Reg_Car_Seats_Field = new System.Windows.Forms.TextBox();
            this.Reg_Car_Seats = new System.Windows.Forms.Label();
            this.Reg_Car_Manufacturer_Cmb = new System.Windows.Forms.ComboBox();
            this.Reg_Car_Lugage_Chck = new System.Windows.Forms.CheckBox();
            this.Reg_Car_Grp_Box.SuspendLayout();
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
            this.Password_Reg_Field.PasswordChar = '*';
            this.Password_Reg_Field.Size = new System.Drawing.Size(183, 22);
            this.Password_Reg_Field.TabIndex = 2;
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
            this.R_Password_Reg_Field.PasswordChar = '*';
            this.R_Password_Reg_Field.Size = new System.Drawing.Size(183, 22);
            this.R_Password_Reg_Field.TabIndex = 4;
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
            // Driver_CheckBox
            // 
            this.Driver_CheckBox.AutoSize = true;
            this.Driver_CheckBox.BackColor = System.Drawing.Color.Transparent;
            this.Driver_CheckBox.Location = new System.Drawing.Point(12, 234);
            this.Driver_CheckBox.Name = "Driver_CheckBox";
            this.Driver_CheckBox.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.Driver_CheckBox.Size = new System.Drawing.Size(72, 21);
            this.Driver_CheckBox.TabIndex = 10;
            this.Driver_CheckBox.Text = ":Driver";
            this.Driver_CheckBox.UseVisualStyleBackColor = false;
            this.Driver_CheckBox.CheckedChanged += new System.EventHandler(this.Driver_CheckBox_CheckedChanged);
            // 
            // Register_Button
            // 
            this.Register_Button.Location = new System.Drawing.Point(15, 261);
            this.Register_Button.Name = "Register_Button";
            this.Register_Button.Size = new System.Drawing.Size(89, 33);
            this.Register_Button.TabIndex = 11;
            this.Register_Button.Text = "Register";
            this.Register_Button.UseVisualStyleBackColor = true;
            this.Register_Button.Click += new System.EventHandler(this.Register_Button_Click);
            // 
            // Back_Reg_Button
            // 
            this.Back_Reg_Button.Location = new System.Drawing.Point(109, 261);
            this.Back_Reg_Button.Name = "Back_Reg_Button";
            this.Back_Reg_Button.Size = new System.Drawing.Size(89, 33);
            this.Back_Reg_Button.TabIndex = 12;
            this.Back_Reg_Button.Text = "Back";
            this.Back_Reg_Button.UseVisualStyleBackColor = true;
            this.Back_Reg_Button.Click += new System.EventHandler(this.Back_Reg_Button_Click);
            // 
            // Reg_Car_Grp_Box
            // 
            this.Reg_Car_Grp_Box.BackColor = System.Drawing.SystemColors.Control;
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Lugage_Chck);
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Manufacturer_Cmb);
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Seats);
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Seats_Field);
            this.Reg_Car_Grp_Box.Controls.Add(this.Car_Reg_Nomer_Field);
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Nomer);
            this.Reg_Car_Grp_Box.Controls.Add(this.Reg_Car_Manufacturer);
            this.Reg_Car_Grp_Box.Location = new System.Drawing.Point(15, 317);
            this.Reg_Car_Grp_Box.Name = "Reg_Car_Grp_Box";
            this.Reg_Car_Grp_Box.Size = new System.Drawing.Size(349, 172);
            this.Reg_Car_Grp_Box.TabIndex = 13;
            this.Reg_Car_Grp_Box.TabStop = false;
            this.Reg_Car_Grp_Box.Text = "Car Info:";
            // 
            // Reg_Car_Manufacturer
            // 
            this.Reg_Car_Manufacturer.AutoSize = true;
            this.Reg_Car_Manufacturer.Location = new System.Drawing.Point(6, 75);
            this.Reg_Car_Manufacturer.Name = "Reg_Car_Manufacturer";
            this.Reg_Car_Manufacturer.Size = new System.Drawing.Size(96, 17);
            this.Reg_Car_Manufacturer.TabIndex = 0;
            this.Reg_Car_Manufacturer.Text = "Manufacturer:";
            // 
            // Reg_Car_Nomer
            // 
            this.Reg_Car_Nomer.AutoSize = true;
            this.Reg_Car_Nomer.Location = new System.Drawing.Point(9, 22);
            this.Reg_Car_Nomer.Name = "Reg_Car_Nomer";
            this.Reg_Car_Nomer.Size = new System.Drawing.Size(65, 17);
            this.Reg_Car_Nomer.TabIndex = 1;
            this.Reg_Car_Nomer.Text = "Serial ID:";
            // 
            // Car_Reg_Nomer_Field
            // 
            this.Car_Reg_Nomer_Field.Location = new System.Drawing.Point(128, 19);
            this.Car_Reg_Nomer_Field.Name = "Car_Reg_Nomer_Field";
            this.Car_Reg_Nomer_Field.Size = new System.Drawing.Size(205, 22);
            this.Car_Reg_Nomer_Field.TabIndex = 2;
            // 
            // Reg_Car_Seats_Field
            // 
            this.Reg_Car_Seats_Field.Location = new System.Drawing.Point(128, 128);
            this.Reg_Car_Seats_Field.Name = "Reg_Car_Seats_Field";
            this.Reg_Car_Seats_Field.Size = new System.Drawing.Size(46, 22);
            this.Reg_Car_Seats_Field.TabIndex = 3;
            // 
            // Reg_Car_Seats
            // 
            this.Reg_Car_Seats.AutoSize = true;
            this.Reg_Car_Seats.Location = new System.Drawing.Point(6, 131);
            this.Reg_Car_Seats.Name = "Reg_Car_Seats";
            this.Reg_Car_Seats.Size = new System.Drawing.Size(118, 17);
            this.Reg_Car_Seats.TabIndex = 4;
            this.Reg_Car_Seats.Text = "Number of Seats:";
            // 
            // Reg_Car_Manufacturer_Cmb
            // 
            this.Reg_Car_Manufacturer_Cmb.FormattingEnabled = true;
            this.Reg_Car_Manufacturer_Cmb.Location = new System.Drawing.Point(128, 72);
            this.Reg_Car_Manufacturer_Cmb.Name = "Reg_Car_Manufacturer_Cmb";
            this.Reg_Car_Manufacturer_Cmb.Size = new System.Drawing.Size(205, 24);
            this.Reg_Car_Manufacturer_Cmb.TabIndex = 5;
            // 
            // Reg_Car_Lugage_Chck
            // 
            this.Reg_Car_Lugage_Chck.AutoSize = true;
            this.Reg_Car_Lugage_Chck.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Reg_Car_Lugage_Chck.Location = new System.Drawing.Point(194, 130);
            this.Reg_Car_Lugage_Chck.Name = "Reg_Car_Lugage_Chck";
            this.Reg_Car_Lugage_Chck.Size = new System.Drawing.Size(139, 21);
            this.Reg_Car_Lugage_Chck.TabIndex = 7;
            this.Reg_Car_Lugage_Chck.Text = "Supports Lugage";
            this.Reg_Car_Lugage_Chck.UseVisualStyleBackColor = true;
            // 
            // RegisterDialog
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(959, 644);
            this.Controls.Add(this.Reg_Car_Grp_Box);
            this.Controls.Add(this.Driver_CheckBox);
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
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Saul - Register";
            this.Load += new System.EventHandler(this.RegisterDialog_Load);
            this.Reg_Car_Grp_Box.ResumeLayout(false);
            this.Reg_Car_Grp_Box.PerformLayout();
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

            if (!InputValidator.Validate_Password(this.Password_Reg_Field.Text, this.R_Password_Reg_Field.Text, true) /* да ги сравни */)
                return false;

            if (!InputValidator.Validate_Ucn(this.Ucn_Reg_Field.Text))
                return false;

            if (!InputValidator.Validate_Full_Name(this.Name_Reg_Field.Text))
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
                    oDatabaseManager.ExecuteQuery(
                        String.Format(GlobalConstants.SELECT_CUSTOMER_ID_BY_USERNAME, this.Username_Reg_Field.Text));

                if (oSqlDataReader.Read())
                    return false;
            }
            catch (Exception oException)
            {
                MessageBox.Show(oException.ToString());
                return false;
            }

            return true;
        }

        private bool Register()
        {
            // Връзваме се към базата
            DatabaseManager oDatabaseManager = new DatabaseManager();

            // Започваме транзакця
            oDatabaseManager.Begin();

            // Добавяме регистрилалия се потребител
            oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.INSERT_CUSTOMER
                , this.Ucn_Reg_Field.Text
                , this.Name_Reg_Field.Text
                , 0 // направени поръчки - като за начало няма
                , this.Driver_CheckBox.CheckState == CheckState.Checked ? (int)Customer.Roles.RoleDriver : (int)Customer.Roles.RoleUser
                , this.Username_Reg_Field.Text
                , this.Password_Reg_Field.Text
                ), true /* в транзакция сме */, true /* няма да четем */);

            // Ако добавяме шофьор
            if (this.Driver_CheckBox.CheckState == CheckState.Checked)
            {
                // Взимаме му ID-то
                SqlDataReader oSqlDataReaderCustId = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.SELECT_CUSTOMER_ID_BY_USERNAME
                    , this.Username_Reg_Field.Text), true /* в транзакция сме */);
                if (!oSqlDataReaderCustId.Read()) // ако няма запис нещо е гръмнало в SQL-а, rollback-ваме транзакцията
                {
                    oDatabaseManager.Rollback();
                    return false;
                }
                int nNewCustomerId = (Int32)(oSqlDataReaderCustId.GetValue((int)Customer.Columns.ID));
                oSqlDataReaderCustId.Close();

                // Добавяме и в таблицата за шофъори
                oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.INSERT_DRIVER
                            , 0 // изпълнени поръчки - като за начало няма
                            , nNewCustomerId
                            , 0 // пари, направени от поръчки, като за начало няма
                            , (int)Driver.DriverStatus.DriverStatusAvailable // при създаване се бъде свободен
                            ), true /* в транзакция сме */, true /* няма да четем */);
            }

            // Ако сме стигнали до тук, затваряме транзакцията
            oDatabaseManager.Commit();

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

            if (!Register())
                return;

            if (this.Driver_CheckBox.Checked)
            {
                if (!this.RegisterCar())
                    return;
            }

            this.DialogResult = DialogResult.OK;
            this.Hide();
        }

        private void Driver_CheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (this.Driver_CheckBox.Checked)
                this.Reg_Car_Grp_Box.Show();
            else
                this.Reg_Car_Grp_Box.Hide();
        }

        private bool RegisterCar()
        {
            // взимаме производителя
            Manufacturer recManufacturer = (Manufacturer)(this.Reg_Car_Manufacturer_Cmb.SelectedItem);

            // проверяваме в базата има ли кола с такъв номер и прозиводител
            if (!this.CheckRegNomerAndManufacturerAvailability(recManufacturer.nId))
                return false;

            // взимаме id на щофьора
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                String.Format(GlobalConstants.SELECT_DRIVER_ID_BY_USERNAME, this.Username_Reg_Field.Text));

            if (!oSqlDataReader.Read())
                return false;

            Int32 nDriverId = (Int32)(oSqlDataReader.GetValue((int)Driver.Columns.ID));
            oSqlDataReader.Close();

            // добавяме колата
            SqlDataReader oSqlDataReader1 = oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.INSERT_CAR
                , this.Car_Reg_Nomer_Field.Text, recManufacturer.nId, this.Reg_Car_Seats_Field.Text
                , this.Reg_Car_Lugage_Chck.Checked ? 1 : 0, nDriverId), false, false);

            return true;
        }

        private bool CheckRegNomerAndManufacturerAvailability(int nManufacturerId)
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_IF_EXISTS_CAR
                , this.Car_Reg_Nomer_Field.Text, nManufacturerId));

            // ако има нещо за четене значи вече има кола с такъв номер и марка 
            if (oSqlDataReader.Read())
            {
                MessageBox.Show(GlobalConstants.CAR_ALREADY_EXISTS);
                return false;
            }

            return true;
        }


    }
}
