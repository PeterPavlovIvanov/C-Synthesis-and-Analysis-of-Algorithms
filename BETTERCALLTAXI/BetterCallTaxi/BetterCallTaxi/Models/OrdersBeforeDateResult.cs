using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi
{
    class OrdersBeforeDateRow
    {
        // Enums
        public enum Columns
        {
            ORD_TIME = 0, REG_NOMER = 1, NAME = 2, ORDERS_COUNTS = 3
        }

        // Полета в отчета
        public DateTime dtOrdDate;
        public string strRegNomer;
        public string strManufacturerName;
        public Int32 nOrdersCounts;

        public bool b_Last_Operation_Status = true;

        public OrdersBeforeDateRow(DateTime dtOrdDate, string strRegNomer, string strManufacturerName, Int32 nOrdersCounts)
        {
            this.dtOrdDate = dtOrdDate;
            this.strRegNomer = strRegNomer;
            this.strManufacturerName = strManufacturerName;
            this.nOrdersCounts = nOrdersCounts;
        }
    }

    class OrdersBeforeDateResult
    {
        public List<OrdersBeforeDateRow> oResultSet;

        public OrdersBeforeDateResult(SqlDataReader oSqlDataReader)
        {
            oResultSet = new List<OrdersBeforeDateRow>();
            Read_Report_Orders_Before_Date(oSqlDataReader);
        }

        public bool Read_Report_Orders_Before_Date(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                OrdersBeforeDateRow oOrdersBeforeDateRow = new OrdersBeforeDateRow(
                      (DateTime)(oSqlDataReader.GetValue((int)OrdersBeforeDateRow.Columns.ORD_TIME))
                    , oSqlDataReader.GetValue((int)OrdersBeforeDateRow.Columns.REG_NOMER).ToString()
                    , oSqlDataReader.GetValue((int)OrdersBeforeDateRow.Columns.NAME).ToString()
                    , (Int32)(oSqlDataReader.GetValue((int)OrdersBeforeDateRow.Columns.ORDERS_COUNTS))
                );

                this.oResultSet.Add(oOrdersBeforeDateRow);
            }

            return true;
        }
    }
}
