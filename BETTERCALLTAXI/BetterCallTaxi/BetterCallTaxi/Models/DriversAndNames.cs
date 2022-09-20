using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class DriversAndNames
    {
        // Enums
        public enum Columns
        {
            ID = 0, COMPLETED_ORDERS = 1, CUSTOMER_ID = 2, MONEY_MADE = 3, STATUS = 4, NAME = 5
        }

        public Driver recDriver;
        public string strName;
        public bool b_Last_Operation_Status = true;

        public DriversAndNames()
        {
            this.recDriver = new Driver();
            this.strName = "";
        }

        public DriversAndNames(Driver recDriver, string strName)
        {
            this.recDriver = recDriver;
            this.strName = strName;
        }

        public DriversAndNames(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = Read_One_Driver(oSqlDataReader);
        }

        private bool Read_One_Driver(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return false;

            this.recDriver.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
            this.recDriver.nCompletedOrders = (Int32)(oSqlDataReader.GetValue((int)Columns.COMPLETED_ORDERS));
            this.recDriver.nCustomerId = (Int32)(oSqlDataReader.GetValue((int)Columns.CUSTOMER_ID));
            this.recDriver.dMoneyMade = (double)(oSqlDataReader.GetValue((int)Columns.MONEY_MADE));
            this.recDriver.bStatus = (System.Boolean)(oSqlDataReader.GetValue((int)Columns.STATUS));
            this.strName = (string)(oSqlDataReader.GetValue((int)Columns.NAME));

            return true;
        }

    }

    class DriversAndNamesReader
    {
        public List<DriversAndNames> oDriversAndNames;

        public DriversAndNamesReader(SqlDataReader oSqlDataReader)
        {
            oDriversAndNames = new List<DriversAndNames>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                DriversAndNames oDriversAndNames = new DriversAndNames( new Driver(
                        (Int32)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.ID))
                        , (Int32)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.COMPLETED_ORDERS))
                        , (Int32)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.CUSTOMER_ID))
                        , (double)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.MONEY_MADE))
                        , (System.Boolean)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.STATUS))
                    ), (string)(oSqlDataReader.GetValue((int)DriversAndNames.Columns.NAME))
                );

                this.oDriversAndNames.Add(oDriversAndNames);
            }
        }

    }
}
