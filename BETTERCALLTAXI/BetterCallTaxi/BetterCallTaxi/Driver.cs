using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi
{
    class Driver
    {
        // Enums
        public enum DriverStatus
        {
            DriverStatusBusy = 0, DriverStatusAvailable = 1
        }

        public enum Columns
        {
            ID = 0, COMPLETED_ORDERS = 1, CUSTOMER_ID = 2, MONEY_MADE = 3, STATUS = 4
        }


        public bool b_Last_Operation_Status = true;

        // Полета от таблиата DRIVERS
        public Int32 nId;
        public Int32 nCompletedOrders;
        public Int32 nCustomerId;
        public double dMoneyMade;
        public bool bStatus;

        public Driver()
        {
            this.nId = 0;
            this.nCompletedOrders = 0;
            this.nCustomerId = 0;
            this.dMoneyMade = 0;
            this.bStatus = false;
        }

        public Driver(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = Read_One_Driver(oSqlDataReader);
        }

        private bool Read_One_Driver(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return false;

            this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
            this.nCompletedOrders = (Int32)(oSqlDataReader.GetValue((int)Columns.COMPLETED_ORDERS));
            this.nCustomerId = (Int32)(oSqlDataReader.GetValue((int)Columns.CUSTOMER_ID));
            this.dMoneyMade = (double)(oSqlDataReader.GetValue((int)Columns.MONEY_MADE));
            this.bStatus = (System.Boolean)(oSqlDataReader.GetValue((int)Columns.STATUS));

            return true;
        }

        public override string ToString()
        {
            string strResult = "ID: {0}\nCOMPLETED_ORDERS: {1}\nCUSTOMER_ID: {2}\nMONEY_MADE: {3}\nSTATUS: {4}\n";
            strResult += this.nId + "; " + this.nCompletedOrders + "; " + this.nCustomerId + "; " +
                this.dMoneyMade + "; " + this.bStatus;
            return strResult;
        }
    }
}
