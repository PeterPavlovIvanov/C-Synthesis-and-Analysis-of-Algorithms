using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class OrdersBeforeDateDialog : Form
    {
        private DateTimePicker Ord_Bfr_Date_Input;
        private Label Ord_Bfr_Date_Label;
        private Button Ord_Bfr_Date_CANCEL;
        private Button Ord_Bfr_Date_OK;

        public OrdersBeforeDateDialog()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.Ord_Bfr_Date_Input = new System.Windows.Forms.DateTimePicker();
            this.Ord_Bfr_Date_Label = new System.Windows.Forms.Label();
            this.Ord_Bfr_Date_OK = new System.Windows.Forms.Button();
            this.Ord_Bfr_Date_CANCEL = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Ord_Bfr_Date_Input
            // 
            this.Ord_Bfr_Date_Input.Location = new System.Drawing.Point(185, 28);
            this.Ord_Bfr_Date_Input.Name = "Ord_Bfr_Date_Input";
            this.Ord_Bfr_Date_Input.Size = new System.Drawing.Size(200, 22);
            this.Ord_Bfr_Date_Input.TabIndex = 0;
            // 
            // Ord_Bfr_Date_Label
            // 
            this.Ord_Bfr_Date_Label.AutoSize = true;
            this.Ord_Bfr_Date_Label.Location = new System.Drawing.Point(12, 28);
            this.Ord_Bfr_Date_Label.Name = "Ord_Bfr_Date_Label";
            this.Ord_Bfr_Date_Label.Size = new System.Drawing.Size(134, 17);
            this.Ord_Bfr_Date_Label.TabIndex = 1;
            this.Ord_Bfr_Date_Label.Text = "End Date of Report:";
            // 
            // Ord_Bfr_Date_OK
            // 
            this.Ord_Bfr_Date_OK.Location = new System.Drawing.Point(183, 67);
            this.Ord_Bfr_Date_OK.Name = "Ord_Bfr_Date_OK";
            this.Ord_Bfr_Date_OK.Size = new System.Drawing.Size(100, 33);
            this.Ord_Bfr_Date_OK.TabIndex = 2;
            this.Ord_Bfr_Date_OK.Text = "OK";
            this.Ord_Bfr_Date_OK.UseVisualStyleBackColor = true;
            this.Ord_Bfr_Date_OK.Click += new System.EventHandler(this.Ord_Bfr_Date_OK_Click);
            // 
            // Ord_Bfr_Date_CANCEL
            // 
            this.Ord_Bfr_Date_CANCEL.Location = new System.Drawing.Point(290, 67);
            this.Ord_Bfr_Date_CANCEL.Name = "Ord_Bfr_Date_CANCEL";
            this.Ord_Bfr_Date_CANCEL.Size = new System.Drawing.Size(96, 33);
            this.Ord_Bfr_Date_CANCEL.TabIndex = 3;
            this.Ord_Bfr_Date_CANCEL.Text = "Cancel";
            this.Ord_Bfr_Date_CANCEL.UseVisualStyleBackColor = true;
            this.Ord_Bfr_Date_CANCEL.Click += new System.EventHandler(this.Ord_Bfr_Date_CANCEL_Click);
            // 
            // OrdersBeforeDateDialog
            // 
            this.ClientSize = new System.Drawing.Size(397, 127);
            this.Controls.Add(this.Ord_Bfr_Date_CANCEL);
            this.Controls.Add(this.Ord_Bfr_Date_OK);
            this.Controls.Add(this.Ord_Bfr_Date_Label);
            this.Controls.Add(this.Ord_Bfr_Date_Input);
            this.Name = "OrdersBeforeDateDialog";
            this.Text = "Orders Before Date Report";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Ord_Bfr_Date_OK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
        }

        private void Ord_Bfr_Date_CANCEL_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }
    }
}
