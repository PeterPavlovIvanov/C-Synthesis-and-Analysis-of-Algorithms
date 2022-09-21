using BetterCallTaxi.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi.Pages
{
    class OrderRequestClaim : Form
    {
        private TextBox Ord_Req_Cust_Name_Field;
        private Label Ord_Req_Adr_From;
        private TextBox Ord_Req_Adr_From_Field;
        private TextBox Ord_Req_Adr_To_Field;
        private Label Ord_Req_Adr_To;
        private TextBox Ord_Req_Ord_Time_Field;
        private Label Ord_Req_Ord_Time;
        private Label Ord_Req_Question;
        private Button Ord_Req_OK_Btn;
        private Button Ord_Req_Cancel_Btn;
        private Label Ord_Req_Cust_Name;
        public OrdReqCustNameAndId oOrdReqCustNameAndId;

        public OrderRequestClaim(int nOrderRequestId)
        {
            InitializeComponent();
            this.SetEnabledFields(false);
            this.GetOrderRequestFromDatabase(nOrderRequestId);
            this.SetDataToFields();
        }

        private void GetOrderRequestFromDatabase(int nOrderRequestId)
        {
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(String.Format(
                GlobalConstants.SELECT_ORDERS_REQUESTS_AND_CUST_NAME_BY_ORDER_REQUEST_ID, nOrderRequestId));
            this.oOrdReqCustNameAndId = new OrdReqCustNameAndId(oSqlDataReader);
            oSqlDataReader.Close();
        }

        private void SetDataToFields()
        {
            this.Ord_Req_Cust_Name_Field.Text = this.oOrdReqCustNameAndId.oOrdReqCustName.strCustName;
            this.Ord_Req_Adr_From_Field.Text = this.oOrdReqCustNameAndId.oOrdReqCustName.strAddressFrom;
            this.Ord_Req_Adr_To_Field.Text = this.oOrdReqCustNameAndId.oOrdReqCustName.strAddressTo;
            this.Ord_Req_Ord_Time_Field.Text = this.oOrdReqCustNameAndId.oOrdReqCustName.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT);
        }

        private void SetEnabledFields(bool bEnabled)
        {
            this.Ord_Req_Cust_Name_Field.Enabled = bEnabled;
            this.Ord_Req_Adr_From_Field.Enabled = bEnabled;
            this.Ord_Req_Adr_To_Field.Enabled = bEnabled;
            this.Ord_Req_Ord_Time_Field.Enabled = bEnabled;
        }

        private void InitializeComponent()
        {
            this.Ord_Req_Cust_Name = new System.Windows.Forms.Label();
            this.Ord_Req_Cust_Name_Field = new System.Windows.Forms.TextBox();
            this.Ord_Req_Adr_From = new System.Windows.Forms.Label();
            this.Ord_Req_Adr_From_Field = new System.Windows.Forms.TextBox();
            this.Ord_Req_Adr_To_Field = new System.Windows.Forms.TextBox();
            this.Ord_Req_Adr_To = new System.Windows.Forms.Label();
            this.Ord_Req_Ord_Time_Field = new System.Windows.Forms.TextBox();
            this.Ord_Req_Ord_Time = new System.Windows.Forms.Label();
            this.Ord_Req_Question = new System.Windows.Forms.Label();
            this.Ord_Req_OK_Btn = new System.Windows.Forms.Button();
            this.Ord_Req_Cancel_Btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Ord_Req_Cust_Name
            // 
            this.Ord_Req_Cust_Name.AutoSize = true;
            this.Ord_Req_Cust_Name.Location = new System.Drawing.Point(12, 53);
            this.Ord_Req_Cust_Name.Name = "Ord_Req_Cust_Name";
            this.Ord_Req_Cust_Name.Size = new System.Drawing.Size(113, 17);
            this.Ord_Req_Cust_Name.TabIndex = 0;
            this.Ord_Req_Cust_Name.Text = "Customer Name:";
            // 
            // Ord_Req_Cust_Name_Field
            // 
            this.Ord_Req_Cust_Name_Field.Location = new System.Drawing.Point(171, 53);
            this.Ord_Req_Cust_Name_Field.Name = "Ord_Req_Cust_Name_Field";
            this.Ord_Req_Cust_Name_Field.Size = new System.Drawing.Size(196, 22);
            this.Ord_Req_Cust_Name_Field.TabIndex = 1;
            // 
            // Ord_Req_Adr_From
            // 
            this.Ord_Req_Adr_From.AutoSize = true;
            this.Ord_Req_Adr_From.Location = new System.Drawing.Point(11, 87);
            this.Ord_Req_Adr_From.Name = "Ord_Req_Adr_From";
            this.Ord_Req_Adr_From.Size = new System.Drawing.Size(100, 17);
            this.Ord_Req_Adr_From.TabIndex = 2;
            this.Ord_Req_Adr_From.Text = "Address From:";
            // 
            // Ord_Req_Adr_From_Field
            // 
            this.Ord_Req_Adr_From_Field.Location = new System.Drawing.Point(171, 87);
            this.Ord_Req_Adr_From_Field.Name = "Ord_Req_Adr_From_Field";
            this.Ord_Req_Adr_From_Field.Size = new System.Drawing.Size(196, 22);
            this.Ord_Req_Adr_From_Field.TabIndex = 3;
            // 
            // Ord_Req_Adr_To_Field
            // 
            this.Ord_Req_Adr_To_Field.Location = new System.Drawing.Point(172, 124);
            this.Ord_Req_Adr_To_Field.Name = "Ord_Req_Adr_To_Field";
            this.Ord_Req_Adr_To_Field.Size = new System.Drawing.Size(196, 22);
            this.Ord_Req_Adr_To_Field.TabIndex = 5;
            // 
            // Ord_Req_Adr_To
            // 
            this.Ord_Req_Adr_To.AutoSize = true;
            this.Ord_Req_Adr_To.Location = new System.Drawing.Point(12, 124);
            this.Ord_Req_Adr_To.Name = "Ord_Req_Adr_To";
            this.Ord_Req_Adr_To.Size = new System.Drawing.Size(139, 17);
            this.Ord_Req_Adr_To.TabIndex = 4;
            this.Ord_Req_Adr_To.Text = "Destination Address:";
            // 
            // Ord_Req_Ord_Time_Field
            // 
            this.Ord_Req_Ord_Time_Field.Location = new System.Drawing.Point(171, 166);
            this.Ord_Req_Ord_Time_Field.Name = "Ord_Req_Ord_Time_Field";
            this.Ord_Req_Ord_Time_Field.Size = new System.Drawing.Size(196, 22);
            this.Ord_Req_Ord_Time_Field.TabIndex = 7;
            // 
            // Ord_Req_Ord_Time
            // 
            this.Ord_Req_Ord_Time.AutoSize = true;
            this.Ord_Req_Ord_Time.Location = new System.Drawing.Point(11, 166);
            this.Ord_Req_Ord_Time.Name = "Ord_Req_Ord_Time";
            this.Ord_Req_Ord_Time.Size = new System.Drawing.Size(100, 17);
            this.Ord_Req_Ord_Time.TabIndex = 6;
            this.Ord_Req_Ord_Time.Text = "Time of Order:";
            // 
            // Ord_Req_Question
            // 
            this.Ord_Req_Question.AutoSize = true;
            this.Ord_Req_Question.Location = new System.Drawing.Point(12, 20);
            this.Ord_Req_Question.Name = "Ord_Req_Question";
            this.Ord_Req_Question.Size = new System.Drawing.Size(344, 17);
            this.Ord_Req_Question.TabIndex = 8;
            this.Ord_Req_Question.Text = "Are you sure you want to take this customer request?";
            // 
            // Ord_Req_OK_Btn
            // 
            this.Ord_Req_OK_Btn.Location = new System.Drawing.Point(147, 264);
            this.Ord_Req_OK_Btn.Name = "Ord_Req_OK_Btn";
            this.Ord_Req_OK_Btn.Size = new System.Drawing.Size(107, 38);
            this.Ord_Req_OK_Btn.TabIndex = 9;
            this.Ord_Req_OK_Btn.Text = "Take Request";
            this.Ord_Req_OK_Btn.UseVisualStyleBackColor = true;
            this.Ord_Req_OK_Btn.Click += new System.EventHandler(this.Ord_Req_OK_Btn_Click);
            // 
            // Ord_Req_Cancel_Btn
            // 
            this.Ord_Req_Cancel_Btn.Location = new System.Drawing.Point(260, 264);
            this.Ord_Req_Cancel_Btn.Name = "Ord_Req_Cancel_Btn";
            this.Ord_Req_Cancel_Btn.Size = new System.Drawing.Size(107, 38);
            this.Ord_Req_Cancel_Btn.TabIndex = 10;
            this.Ord_Req_Cancel_Btn.Text = "Dissmis";
            this.Ord_Req_Cancel_Btn.UseVisualStyleBackColor = true;
            this.Ord_Req_Cancel_Btn.Click += new System.EventHandler(this.Ord_Req_Cancel_Btn_Click);
            // 
            // OrderRequestClaim
            // 
            this.ClientSize = new System.Drawing.Size(396, 314);
            this.Controls.Add(this.Ord_Req_Cancel_Btn);
            this.Controls.Add(this.Ord_Req_OK_Btn);
            this.Controls.Add(this.Ord_Req_Question);
            this.Controls.Add(this.Ord_Req_Ord_Time_Field);
            this.Controls.Add(this.Ord_Req_Ord_Time);
            this.Controls.Add(this.Ord_Req_Adr_To_Field);
            this.Controls.Add(this.Ord_Req_Adr_To);
            this.Controls.Add(this.Ord_Req_Adr_From_Field);
            this.Controls.Add(this.Ord_Req_Adr_From);
            this.Controls.Add(this.Ord_Req_Cust_Name_Field);
            this.Controls.Add(this.Ord_Req_Cust_Name);
            this.Name = "OrderRequestClaim";
            this.Text = "Take Customer Order";
            this.Load += new System.EventHandler(this.OrderRequestClaim_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void OrderRequestClaim_Load(object sender, EventArgs e)
        {

        }

        private void Ord_Req_OK_Btn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void Ord_Req_Cancel_Btn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
