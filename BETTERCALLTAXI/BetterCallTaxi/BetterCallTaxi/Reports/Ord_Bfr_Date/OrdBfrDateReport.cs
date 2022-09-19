using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class OrdBfrDateReport : Form
    {
        private ListBox Ord_Bfr_Date_ListBox;

        public OrdBfrDateReport(SqlDataReader oSqlDataReader, string strDate)
        {
            InitializeComponent();
            SetColumnHeaders();
            this.Text = String.Format(this.Text, strDate);

            OrdersBeforeDateResult oOrdersBeforeDateResult = new OrdersBeforeDateResult(oSqlDataReader);
            foreach (OrdersBeforeDateRow row in oOrdersBeforeDateResult.oResultSet)
            {
                this.Ord_Bfr_Date_ListBox.Items.Add(
                                row.dtOrdDate.ToString(GlobalConstants.DATE_FORMAT)
                              + GlobalConstants.TAB + row.strRegNomer
                              + GlobalConstants.TAB + row.strManufacturerName
                              + GlobalConstants.TAB + row.nOrdersCounts.ToString()
                );
            }
        }

        private void SetColumnHeaders()
        {
            this.Ord_Bfr_Date_ListBox.Items.Clear();
            this.Ord_Bfr_Date_ListBox.Items.Add(GlobalConstants.ORDER_TIME + GlobalConstants.TAB 
                + GlobalConstants.CAR_REG_NUMBER + GlobalConstants.TAB 
                + GlobalConstants.MANUFACTURER_NAME + GlobalConstants.TAB 
                + GlobalConstants.TOTAL_ORDERS_COUNTS);
        }

        private void InitializeComponent()
        {
            this.Ord_Bfr_Date_ListBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // Ord_Bfr_Date_ListBox
            // 
            this.Ord_Bfr_Date_ListBox.FormattingEnabled = true;
            this.Ord_Bfr_Date_ListBox.ItemHeight = 16;
            this.Ord_Bfr_Date_ListBox.Location = new System.Drawing.Point(13, 13);
            this.Ord_Bfr_Date_ListBox.Name = "Ord_Bfr_Date_ListBox";
            this.Ord_Bfr_Date_ListBox.Size = new System.Drawing.Size(755, 420);
            this.Ord_Bfr_Date_ListBox.TabIndex = 0;
            this.Ord_Bfr_Date_ListBox.SelectedIndexChanged += new System.EventHandler(this.Ord_Bfr_Date_ListBox_SelectedIndexChanged);
            // 
            // OrdBfrDateReport
            // 
            this.ClientSize = new System.Drawing.Size(780, 445);
            this.Controls.Add(this.Ord_Bfr_Date_ListBox);
            this.Name = "OrdBfrDateReport";
            this.Text = "Orders Before Date: {0}";
            this.Load += new System.EventHandler(this.OrdBfrDateReport_Load);
            this.ResumeLayout(false);

        }

        private void Ord_Bfr_Date_ListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void OrdBfrDateReport_Load(object sender, EventArgs e)
        {

        }
    }
}
