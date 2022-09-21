using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi.Pages
{
    class LogoutPopUp : Form
    {
        private Label Logout_Question;
        private Button Logout_Ok;
        private Button Logout_Cancel;

        public LogoutPopUp()
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT_LOGOUT;
        }

        private void InitializeComponent()
        {
            this.Logout_Question = new System.Windows.Forms.Label();
            this.Logout_Ok = new System.Windows.Forms.Button();
            this.Logout_Cancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Logout_Question
            // 
            this.Logout_Question.AutoSize = true;
            this.Logout_Question.Location = new System.Drawing.Point(12, 26);
            this.Logout_Question.Name = "Logout_Question";
            this.Logout_Question.Size = new System.Drawing.Size(220, 17);
            this.Logout_Question.TabIndex = 0;
            this.Logout_Question.Text = "Are you sure you want to log out?";
            // 
            // Logout_Ok
            // 
            this.Logout_Ok.Location = new System.Drawing.Point(153, 97);
            this.Logout_Ok.Name = "Logout_Ok";
            this.Logout_Ok.Size = new System.Drawing.Size(109, 39);
            this.Logout_Ok.TabIndex = 1;
            this.Logout_Ok.Text = "OK";
            this.Logout_Ok.UseVisualStyleBackColor = true;
            this.Logout_Ok.Click += new System.EventHandler(this.Logout_Ok_Click);
            // 
            // Logout_Cancel
            // 
            this.Logout_Cancel.Location = new System.Drawing.Point(268, 97);
            this.Logout_Cancel.Name = "Logout_Cancel";
            this.Logout_Cancel.Size = new System.Drawing.Size(109, 39);
            this.Logout_Cancel.TabIndex = 2;
            this.Logout_Cancel.Text = "Cancel";
            this.Logout_Cancel.UseVisualStyleBackColor = true;
            this.Logout_Cancel.Click += new System.EventHandler(this.Logout_Cancel_Click);
            // 
            // LogoutPopUp
            // 
            this.ClientSize = new System.Drawing.Size(389, 148);
            this.Controls.Add(this.Logout_Cancel);
            this.Controls.Add(this.Logout_Ok);
            this.Controls.Add(this.Logout_Question);
            this.Name = "LogoutPopUp";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Logout";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Logout_Ok_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void Logout_Cancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
