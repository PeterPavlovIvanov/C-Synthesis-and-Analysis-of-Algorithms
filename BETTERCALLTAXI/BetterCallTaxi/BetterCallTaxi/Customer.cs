using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi
{
    class Customer
    {
        public enum Columns 
        {
            ID = 0, UCN, NAME, ORDERS_MADE, ROLE_ID, USERNAME, PASSWORD
        }

        public Int32 nId;
        public string strUcn;
        public string strName;
        public Int32 nOrdersMade;
        public Int32 nRoleId;
        public string strUsername;
        public Byte[] byPassword;

        public Customer()
        {
            this.nId = 0;
            this.strUcn = "";
            this.strName = "";
            this.nOrdersMade = 0;
            this.nRoleId = 0;
            this.strUsername = "";
        }

        public Customer(SqlDataReader oSqlDataReader)
        {
            Read_Data(oSqlDataReader);
        }

        public void Read_Data(SqlDataReader oSqlDataReader)
        {
            this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
            this.strUcn = oSqlDataReader.GetValue((int)Columns.UCN).ToString();
            this.strName = oSqlDataReader.GetValue((int)Columns.NAME).ToString();
            this.nOrdersMade = (Int32)(oSqlDataReader.GetValue((int)Columns.ORDERS_MADE));
            this.nRoleId = (Int32)(oSqlDataReader.GetValue((int)Columns.ROLE_ID));
            this.strUsername = oSqlDataReader.GetValue((int)Columns.USERNAME).ToString();
            this.byPassword = (byte[])(oSqlDataReader.GetValue((int)Columns.PASSWORD));
        }

        public override string ToString()
        {
            string strResult = "";
            strResult += this.nId + "; " + this.strUcn + "; " + this.strName + "; " +
                this.nOrdersMade + "; " + this.nRoleId + "; " + this.strUsername + "; " + this.byPassword + ";\n";
            return strResult;
        }
    }
}
