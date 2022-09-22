using BetterCallTaxi.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi.Reports.Customers
{
    class CustomersFilterDialog : Form
    {
        private Button Cust_Filt_Cancel_Btn;
        private GroupBox Cust_Filt_Grp_Box;
        private ComboBox Cust_Filt_Role_Cmb;
        private CheckBox Cust_Filt_Role_Chk;
        private TextBox Cust_Filt_Ucn_Field;
        private CheckBox Cust_Filt_Ucn_Chk;
        private TextBox Cust_Filt_Name_Field;
        private CheckBox Cust_Filt_Name_Chk;
        private TextBox Cust_Filt_Username_Field;
        private CheckBox Cust_Filt_Username_Chk;
        private Button Cust_Filt_Ok_Btn;

        public CustomersFilterDialog()
        {
            InitializeComponent();
            this.SetFieldsStatus();
            this.FillRolesComboFromDatabase();
        }

        private void InitializeComponent()
        {
            this.Cust_Filt_Ok_Btn = new System.Windows.Forms.Button();
            this.Cust_Filt_Cancel_Btn = new System.Windows.Forms.Button();
            this.Cust_Filt_Grp_Box = new System.Windows.Forms.GroupBox();
            this.Cust_Filt_Role_Cmb = new System.Windows.Forms.ComboBox();
            this.Cust_Filt_Role_Chk = new System.Windows.Forms.CheckBox();
            this.Cust_Filt_Ucn_Field = new System.Windows.Forms.TextBox();
            this.Cust_Filt_Ucn_Chk = new System.Windows.Forms.CheckBox();
            this.Cust_Filt_Name_Field = new System.Windows.Forms.TextBox();
            this.Cust_Filt_Name_Chk = new System.Windows.Forms.CheckBox();
            this.Cust_Filt_Username_Field = new System.Windows.Forms.TextBox();
            this.Cust_Filt_Username_Chk = new System.Windows.Forms.CheckBox();
            this.Cust_Filt_Grp_Box.SuspendLayout();
            this.SuspendLayout();
            // 
            // Cust_Filt_Ok_Btn
            // 
            this.Cust_Filt_Ok_Btn.Location = new System.Drawing.Point(146, 255);
            this.Cust_Filt_Ok_Btn.Name = "Cust_Filt_Ok_Btn";
            this.Cust_Filt_Ok_Btn.Size = new System.Drawing.Size(100, 40);
            this.Cust_Filt_Ok_Btn.TabIndex = 0;
            this.Cust_Filt_Ok_Btn.Text = "OK";
            this.Cust_Filt_Ok_Btn.UseVisualStyleBackColor = true;
            this.Cust_Filt_Ok_Btn.Click += new System.EventHandler(this.Cust_Filt_Ok_Btn_Click);
            // 
            // Cust_Filt_Cancel_Btn
            // 
            this.Cust_Filt_Cancel_Btn.Location = new System.Drawing.Point(256, 255);
            this.Cust_Filt_Cancel_Btn.Name = "Cust_Filt_Cancel_Btn";
            this.Cust_Filt_Cancel_Btn.Size = new System.Drawing.Size(100, 40);
            this.Cust_Filt_Cancel_Btn.TabIndex = 1;
            this.Cust_Filt_Cancel_Btn.Text = "Cancel";
            this.Cust_Filt_Cancel_Btn.UseVisualStyleBackColor = true;
            this.Cust_Filt_Cancel_Btn.Click += new System.EventHandler(this.Cust_Filt_Cancel_Btn_Click);
            // 
            // Cust_Filt_Grp_Box
            // 
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Role_Cmb);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Role_Chk);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Ucn_Field);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Ucn_Chk);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Name_Field);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Name_Chk);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Username_Field);
            this.Cust_Filt_Grp_Box.Controls.Add(this.Cust_Filt_Username_Chk);
            this.Cust_Filt_Grp_Box.Location = new System.Drawing.Point(13, 13);
            this.Cust_Filt_Grp_Box.Name = "Cust_Filt_Grp_Box";
            this.Cust_Filt_Grp_Box.Size = new System.Drawing.Size(349, 189);
            this.Cust_Filt_Grp_Box.TabIndex = 2;
            this.Cust_Filt_Grp_Box.TabStop = false;
            this.Cust_Filt_Grp_Box.Text = "Filter Fields";
            // 
            // Cust_Filt_Role_Cmb
            // 
            this.Cust_Filt_Role_Cmb.FormattingEnabled = true;
            this.Cust_Filt_Role_Cmb.Location = new System.Drawing.Point(133, 150);
            this.Cust_Filt_Role_Cmb.Name = "Cust_Filt_Role_Cmb";
            this.Cust_Filt_Role_Cmb.Size = new System.Drawing.Size(210, 24);
            this.Cust_Filt_Role_Cmb.TabIndex = 8;
            // 
            // Cust_Filt_Role_Chk
            // 
            this.Cust_Filt_Role_Chk.AutoSize = true;
            this.Cust_Filt_Role_Chk.Location = new System.Drawing.Point(6, 150);
            this.Cust_Filt_Role_Chk.Name = "Cust_Filt_Role_Chk";
            this.Cust_Filt_Role_Chk.Size = new System.Drawing.Size(63, 21);
            this.Cust_Filt_Role_Chk.TabIndex = 7;
            this.Cust_Filt_Role_Chk.Text = "Role:";
            this.Cust_Filt_Role_Chk.UseVisualStyleBackColor = true;
            this.Cust_Filt_Role_Chk.CheckedChanged += new System.EventHandler(this.Cust_Filt_Role_Chk_CheckedChanged);
            // 
            // Cust_Filt_Ucn_Field
            // 
            this.Cust_Filt_Ucn_Field.Location = new System.Drawing.Point(133, 107);
            this.Cust_Filt_Ucn_Field.Name = "Cust_Filt_Ucn_Field";
            this.Cust_Filt_Ucn_Field.Size = new System.Drawing.Size(210, 22);
            this.Cust_Filt_Ucn_Field.TabIndex = 6;
            // 
            // Cust_Filt_Ucn_Chk
            // 
            this.Cust_Filt_Ucn_Chk.AutoSize = true;
            this.Cust_Filt_Ucn_Chk.Location = new System.Drawing.Point(6, 107);
            this.Cust_Filt_Ucn_Chk.Name = "Cust_Filt_Ucn_Chk";
            this.Cust_Filt_Ucn_Chk.Size = new System.Drawing.Size(63, 21);
            this.Cust_Filt_Ucn_Chk.TabIndex = 5;
            this.Cust_Filt_Ucn_Chk.Text = "UCN:";
            this.Cust_Filt_Ucn_Chk.UseVisualStyleBackColor = true;
            this.Cust_Filt_Ucn_Chk.CheckedChanged += new System.EventHandler(this.Cust_Filt_Ucn_Chk_CheckedChanged);
            // 
            // Cust_Filt_Name_Field
            // 
            this.Cust_Filt_Name_Field.Location = new System.Drawing.Point(133, 68);
            this.Cust_Filt_Name_Field.Name = "Cust_Filt_Name_Field";
            this.Cust_Filt_Name_Field.Size = new System.Drawing.Size(210, 22);
            this.Cust_Filt_Name_Field.TabIndex = 4;
            // 
            // Cust_Filt_Name_Chk
            // 
            this.Cust_Filt_Name_Chk.AutoSize = true;
            this.Cust_Filt_Name_Chk.Location = new System.Drawing.Point(6, 68);
            this.Cust_Filt_Name_Chk.Name = "Cust_Filt_Name_Chk";
            this.Cust_Filt_Name_Chk.Size = new System.Drawing.Size(71, 21);
            this.Cust_Filt_Name_Chk.TabIndex = 3;
            this.Cust_Filt_Name_Chk.Text = "Name:";
            this.Cust_Filt_Name_Chk.UseVisualStyleBackColor = true;
            this.Cust_Filt_Name_Chk.CheckedChanged += new System.EventHandler(this.Cust_Filt_Name_Chk_CheckedChanged);
            // 
            // Cust_Filt_Username_Field
            // 
            this.Cust_Filt_Username_Field.Location = new System.Drawing.Point(133, 26);
            this.Cust_Filt_Username_Field.Name = "Cust_Filt_Username_Field";
            this.Cust_Filt_Username_Field.Size = new System.Drawing.Size(210, 22);
            this.Cust_Filt_Username_Field.TabIndex = 2;
            // 
            // Cust_Filt_Username_Chk
            // 
            this.Cust_Filt_Username_Chk.AutoSize = true;
            this.Cust_Filt_Username_Chk.Location = new System.Drawing.Point(6, 26);
            this.Cust_Filt_Username_Chk.Name = "Cust_Filt_Username_Chk";
            this.Cust_Filt_Username_Chk.Size = new System.Drawing.Size(99, 21);
            this.Cust_Filt_Username_Chk.TabIndex = 1;
            this.Cust_Filt_Username_Chk.Text = "Username:";
            this.Cust_Filt_Username_Chk.UseVisualStyleBackColor = true;
            this.Cust_Filt_Username_Chk.CheckedChanged += new System.EventHandler(this.Cust_Filt_Username_Chk_CheckedChanged);
            // 
            // CustomersFilterDialog
            // 
            this.ClientSize = new System.Drawing.Size(374, 307);
            this.Controls.Add(this.Cust_Filt_Grp_Box);
            this.Controls.Add(this.Cust_Filt_Cancel_Btn);
            this.Controls.Add(this.Cust_Filt_Ok_Btn);
            this.Name = "CustomersFilterDialog";
            this.Text = "Filter Customers Report";
            this.Load += new System.EventHandler(this.CustomersFilterDialog_Load);
            this.Cust_Filt_Grp_Box.ResumeLayout(false);
            this.Cust_Filt_Grp_Box.PerformLayout();
            this.ResumeLayout(false);

        }

        private void Cust_Filt_Cancel_Btn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }

        public string FormSelectFilterQuery()
        {
            string strQuery = GlobalConstants.SELECT_ALL_CUSTOMERS;

            if (this.Cust_Filt_Username_Chk.Checked || this.Cust_Filt_Name_Chk.Checked
                || this.Cust_Filt_Role_Chk.Checked || this.Cust_Filt_Ucn_Chk.Checked)
            {
                strQuery += " WHERE ";
                bool bPutAnd = false;

                if (this.Cust_Filt_Username_Chk.Checked)
                {
                    strQuery += " USERNAME LIKE '" + this.Cust_Filt_Username_Field.Text + "%' ";
                    bPutAnd = true;
                }

                if (this.Cust_Filt_Name_Chk.Checked)
                {
                    if (bPutAnd)
                        strQuery += " AND ";

                    strQuery += " NAME LIKE '" + this.Cust_Filt_Name_Field.Text + "%' ";
                    bPutAnd = true;
                }

                if (this.Cust_Filt_Role_Chk.Checked)
                {
                    if (bPutAnd)
                        strQuery += " AND ";

                    strQuery += " ROLE_ID = " + this.Cust_Filt_Role_Cmb.SelectedValue;
                    bPutAnd = true;
                }

                if (this.Cust_Filt_Ucn_Chk.Checked)
                {
                    if (bPutAnd)
                        strQuery += " AND ";
                    strQuery += " UCN LIKE '" + this.Cust_Filt_Ucn_Field.Text + "%' ";
                    bPutAnd = true;
                }
            }

            return strQuery;
        }

        private void Cust_Filt_Ok_Btn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
        }

        private void FillRolesComboFromDatabase()
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ALL_ROLES);
            RolesReader oRolesReader = new RolesReader();
            oRolesReader.Read_Many_Roles(oSqlDataReader);
            oSqlDataReader.Close();

            this.Cust_Filt_Role_Cmb.DataSource = oRolesReader.oRoles;
            this.Cust_Filt_Role_Cmb.DisplayMember = "strRole";
            this.Cust_Filt_Role_Cmb.ValueMember = "nId";
        }

        private void SetFieldsStatus(bool bEnabled = false)
        {
            this.Cust_Filt_Username_Field.Enabled = bEnabled;
            this.Cust_Filt_Name_Field.Enabled = bEnabled;
            this.Cust_Filt_Role_Cmb.Enabled = bEnabled;
            this.Cust_Filt_Ucn_Field.Enabled = bEnabled;
        }

        private void Cust_Filt_Username_Chk_CheckedChanged(object sender, EventArgs e)
        {
            if (this.Cust_Filt_Username_Chk.Checked == true)
                this.Cust_Filt_Username_Field.Enabled = true;
            else
                this.Cust_Filt_Username_Field.Enabled = false;
        }

        private void Cust_Filt_Name_Chk_CheckedChanged(object sender, EventArgs e)
        {
            if (this.Cust_Filt_Name_Chk.Checked == true)
                this.Cust_Filt_Name_Field.Enabled = true;
            else
                this.Cust_Filt_Name_Field.Enabled = false;
        }

        private void Cust_Filt_Ucn_Chk_CheckedChanged(object sender, EventArgs e)
        {
            if (this.Cust_Filt_Ucn_Chk.Checked == true)
                this.Cust_Filt_Ucn_Field.Enabled = true;
            else
                this.Cust_Filt_Ucn_Field.Enabled = false;
        }

        private void Cust_Filt_Role_Chk_CheckedChanged(object sender, EventArgs e)
        {
            if (this.Cust_Filt_Role_Chk.Checked == true)
                this.Cust_Filt_Role_Cmb.Enabled = true;
            else
                this.Cust_Filt_Role_Cmb.Enabled = false;
        }

        private void CustomersFilterDialog_Load(object sender, EventArgs e)
        {

        }
    }
}
