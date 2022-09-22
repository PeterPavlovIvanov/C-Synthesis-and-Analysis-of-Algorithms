using BetterCallTaxi.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi.Pages
{
    class MarkOrderAsCompleted : Form
    {
        private Label Mark_Ord_Adr_From;
        private Label Mark_Ord_Adr_To;
        private Label Mark_Ord_Driving_Time;
        private Label Mark_Ord_Adr_Ord_Time;
        private Label Mark_Ord_Distance;
        private Label Mark_Ord_Fare;
        private TextBox Mark_Ord_Adr_From_Field;
        private TextBox Mark_Ord_Adr_To_Field;
        private TextBox Mark_Ord_Ord_Time_Field;
        private DateTimePicker Mark_Ord_Driving_Time_Field;
        private TextBox Mark_Ord_Distance_Field;
        private TextBox Mark_Ord_Cost_Field;
        private Button Mark_Ord_OK_Btn;
        private Button Mark_Ord_Cancel_Btn;
        public Order recOrder;

        public MarkOrderAsCompleted(Order recOrder)
        {
            InitializeComponent();
            this.FillOrderData(recOrder);
        }

        private void FillOrderData(Order recOrder)
        {
            this.recOrder = recOrder;
            this.Mark_Ord_Adr_From.Text = recOrder.strAddressFrom;
            this.Mark_Ord_Adr_To.Text = recOrder.strAddressTo;
            this.Mark_Ord_Ord_Time_Field.Text = recOrder.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT);
        }

        private void SetDateTimePickerToTimePicker()
        {
            Mark_Ord_Driving_Time_Field = new DateTimePicker();
            Mark_Ord_Driving_Time_Field.Format = DateTimePickerFormat.Custom;
            Mark_Ord_Driving_Time_Field.CustomFormat = "mm:ss";
            Mark_Ord_Driving_Time_Field.ShowUpDown = true;
        }

        private void InitializeComponent()
        {
            this.Mark_Ord_Adr_From = new System.Windows.Forms.Label();
            this.Mark_Ord_Adr_To = new System.Windows.Forms.Label();
            this.Mark_Ord_Driving_Time = new System.Windows.Forms.Label();
            this.Mark_Ord_Adr_Ord_Time = new System.Windows.Forms.Label();
            this.Mark_Ord_Distance = new System.Windows.Forms.Label();
            this.Mark_Ord_Fare = new System.Windows.Forms.Label();
            if(this.Mark_Ord_Adr_From_Field == null)
                this.Mark_Ord_Adr_From_Field = new System.Windows.Forms.TextBox();
            if(this.Mark_Ord_Adr_To_Field == null)
                this.Mark_Ord_Adr_To_Field = new System.Windows.Forms.TextBox();
            if (this.Mark_Ord_Ord_Time_Field == null)
                this.Mark_Ord_Ord_Time_Field = new System.Windows.Forms.TextBox();
            if (this.Mark_Ord_Driving_Time_Field == null)
                this.SetDateTimePickerToTimePicker();
            if (this.Mark_Ord_Distance_Field == null)
                this.Mark_Ord_Distance_Field = new System.Windows.Forms.TextBox();
            if (this.Mark_Ord_Cost_Field == null)
                this.Mark_Ord_Cost_Field = new System.Windows.Forms.TextBox();
            this.Mark_Ord_OK_Btn = new System.Windows.Forms.Button();
            this.Mark_Ord_Cancel_Btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Mark_Ord_Adr_From
            // 
            this.Mark_Ord_Adr_From.AutoSize = true;
            this.Mark_Ord_Adr_From.Location = new System.Drawing.Point(13, 27);
            this.Mark_Ord_Adr_From.Name = "Mark_Ord_Adr_From";
            this.Mark_Ord_Adr_From.Size = new System.Drawing.Size(100, 17);
            this.Mark_Ord_Adr_From.TabIndex = 0;
            this.Mark_Ord_Adr_From.Text = "Address From:";
            // 
            // Mark_Ord_Adr_To
            // 
            this.Mark_Ord_Adr_To.AutoSize = true;
            this.Mark_Ord_Adr_To.Location = new System.Drawing.Point(13, 80);
            this.Mark_Ord_Adr_To.Name = "Mark_Ord_Adr_To";
            this.Mark_Ord_Adr_To.Size = new System.Drawing.Size(139, 17);
            this.Mark_Ord_Adr_To.TabIndex = 1;
            this.Mark_Ord_Adr_To.Text = "Destination Address:";
            // 
            // Mark_Ord_Driving_Time
            // 
            this.Mark_Ord_Driving_Time.AutoSize = true;
            this.Mark_Ord_Driving_Time.Location = new System.Drawing.Point(13, 190);
            this.Mark_Ord_Driving_Time.Name = "Mark_Ord_Driving_Time";
            this.Mark_Ord_Driving_Time.Size = new System.Drawing.Size(91, 17);
            this.Mark_Ord_Driving_Time.TabIndex = 2;
            this.Mark_Ord_Driving_Time.Text = "Driving Time:";
            // 
            // Mark_Ord_Adr_Ord_Time
            // 
            this.Mark_Ord_Adr_Ord_Time.AutoSize = true;
            this.Mark_Ord_Adr_Ord_Time.Location = new System.Drawing.Point(12, 133);
            this.Mark_Ord_Adr_Ord_Time.Name = "Mark_Ord_Adr_Ord_Time";
            this.Mark_Ord_Adr_Ord_Time.Size = new System.Drawing.Size(99, 17);
            this.Mark_Ord_Adr_Ord_Time.TabIndex = 3;
            this.Mark_Ord_Adr_Ord_Time.Text = "Date of Order:";
            // 
            // Mark_Ord_Distance
            // 
            this.Mark_Ord_Distance.AutoSize = true;
            this.Mark_Ord_Distance.Location = new System.Drawing.Point(12, 247);
            this.Mark_Ord_Distance.Name = "Mark_Ord_Distance";
            this.Mark_Ord_Distance.Size = new System.Drawing.Size(67, 17);
            this.Mark_Ord_Distance.TabIndex = 4;
            this.Mark_Ord_Distance.Text = "Distance:";
            // 
            // Mark_Ord_Fare
            // 
            this.Mark_Ord_Fare.AutoSize = true;
            this.Mark_Ord_Fare.Location = new System.Drawing.Point(12, 310);
            this.Mark_Ord_Fare.Name = "Mark_Ord_Fare";
            this.Mark_Ord_Fare.Size = new System.Drawing.Size(40, 17);
            this.Mark_Ord_Fare.TabIndex = 5;
            this.Mark_Ord_Fare.Text = "Cost:";
            // 
            // Mark_Ord_Adr_From_Field
            // 
            this.Mark_Ord_Adr_From_Field.Enabled = false;
            this.Mark_Ord_Adr_From_Field.Location = new System.Drawing.Point(199, 27);
            this.Mark_Ord_Adr_From_Field.Name = "Mark_Ord_Adr_From_Field";
            this.Mark_Ord_Adr_From_Field.Size = new System.Drawing.Size(199, 22);
            this.Mark_Ord_Adr_From_Field.TabIndex = 6;
            // 
            // Mark_Ord_Adr_To_Field
            // 
            this.Mark_Ord_Adr_To_Field.Enabled = false;
            this.Mark_Ord_Adr_To_Field.Location = new System.Drawing.Point(199, 80);
            this.Mark_Ord_Adr_To_Field.Name = "Mark_Ord_Adr_To_Field";
            this.Mark_Ord_Adr_To_Field.Size = new System.Drawing.Size(199, 22);
            this.Mark_Ord_Adr_To_Field.TabIndex = 7;
            // 
            // Mark_Ord_Ord_Time_Field
            // 
            this.Mark_Ord_Ord_Time_Field.Enabled = false;
            this.Mark_Ord_Ord_Time_Field.Location = new System.Drawing.Point(199, 133);
            this.Mark_Ord_Ord_Time_Field.Name = "Mark_Ord_Ord_Time_Field";
            this.Mark_Ord_Ord_Time_Field.Size = new System.Drawing.Size(199, 22);
            this.Mark_Ord_Ord_Time_Field.TabIndex = 8;
            // 
            // Mark_Ord_Driving_Time_Field
            // 
            this.Mark_Ord_Driving_Time_Field.Location = new System.Drawing.Point(199, 190);
            this.Mark_Ord_Driving_Time_Field.Name = "Mark_Ord_Driving_Time_Field";
            this.Mark_Ord_Driving_Time_Field.Size = new System.Drawing.Size(200, 22);
            this.Mark_Ord_Driving_Time_Field.TabIndex = 9;
            // 
            // Mark_Ord_Distance_Field
            // 
            this.Mark_Ord_Distance_Field.Location = new System.Drawing.Point(200, 247);
            this.Mark_Ord_Distance_Field.Name = "Mark_Ord_Distance_Field";
            this.Mark_Ord_Distance_Field.Size = new System.Drawing.Size(199, 22);
            this.Mark_Ord_Distance_Field.TabIndex = 10;
            // 
            // Mark_Ord_Cost_Field
            // 
            this.Mark_Ord_Cost_Field.Location = new System.Drawing.Point(199, 310);
            this.Mark_Ord_Cost_Field.Name = "Mark_Ord_Cost_Field";
            this.Mark_Ord_Cost_Field.Size = new System.Drawing.Size(199, 22);
            this.Mark_Ord_Cost_Field.TabIndex = 11;
            // 
            // Mark_Ord_OK_Btn
            // 
            this.Mark_Ord_OK_Btn.Location = new System.Drawing.Point(79, 371);
            this.Mark_Ord_OK_Btn.Name = "Mark_Ord_OK_Btn";
            this.Mark_Ord_OK_Btn.Size = new System.Drawing.Size(157, 41);
            this.Mark_Ord_OK_Btn.TabIndex = 12;
            this.Mark_Ord_OK_Btn.Text = "Mark as Completed";
            this.Mark_Ord_OK_Btn.UseVisualStyleBackColor = true;
            this.Mark_Ord_OK_Btn.Click += new System.EventHandler(this.Mark_Ord_OK_Btn_Click);
            // 
            // Mark_Ord_Cancel_Btn
            // 
            this.Mark_Ord_Cancel_Btn.Location = new System.Drawing.Point(242, 371);
            this.Mark_Ord_Cancel_Btn.Name = "Mark_Ord_Cancel_Btn";
            this.Mark_Ord_Cancel_Btn.Size = new System.Drawing.Size(157, 41);
            this.Mark_Ord_Cancel_Btn.TabIndex = 13;
            this.Mark_Ord_Cancel_Btn.Text = "Cancel";
            this.Mark_Ord_Cancel_Btn.UseVisualStyleBackColor = true;
            this.Mark_Ord_Cancel_Btn.Click += new System.EventHandler(this.Mark_Ord_Cancel_Btn_Click);
            // 
            // MarkOtderAsCompleted
            // 
            this.ClientSize = new System.Drawing.Size(410, 424);
            this.Controls.Add(this.Mark_Ord_Cancel_Btn);
            this.Controls.Add(this.Mark_Ord_OK_Btn);
            this.Controls.Add(this.Mark_Ord_Cost_Field);
            this.Controls.Add(this.Mark_Ord_Distance_Field);
            this.Controls.Add(this.Mark_Ord_Driving_Time_Field);
            this.Controls.Add(this.Mark_Ord_Ord_Time_Field);
            this.Controls.Add(this.Mark_Ord_Adr_To_Field);
            this.Controls.Add(this.Mark_Ord_Adr_From_Field);
            this.Controls.Add(this.Mark_Ord_Fare);
            this.Controls.Add(this.Mark_Ord_Distance);
            this.Controls.Add(this.Mark_Ord_Adr_Ord_Time);
            this.Controls.Add(this.Mark_Ord_Driving_Time);
            this.Controls.Add(this.Mark_Ord_Adr_To);
            this.Controls.Add(this.Mark_Ord_Adr_From);
            this.Name = "MarkOtderAsCompleted";
            this.Text = "Mark Order as Completed";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Mark_Ord_OK_Btn_Click(object sender, EventArgs e)
        {
            this.recOrder.dDistance = Double.Parse(this.Mark_Ord_Distance_Field.Text);
            this.recOrder.dFare = Double.Parse(this.Mark_Ord_Cost_Field.Text);
            String[] oArr = this.Mark_Ord_Driving_Time_Field.Text.Split(':');
            this.recOrder.tDrivingTime = new TimeSpan(0, int.Parse(oArr[0]), int.Parse((oArr[1])));
            
            this.DialogResult = DialogResult.OK;
        }

        private void Mark_Ord_Cancel_Btn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }
    }
}
