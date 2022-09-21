using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class OrderRequest
    {
        // Enums
        public enum Columns
        {
            ID = 0, CUSTOMER_ID = 1, ADDRESS_FROM = 2, ADDRESS_TO = 3, ORD_TIME = 4
        }

        // Table Fields
        public Int32 nId;
        public Int32 nCustomerId;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime;

        public bool b_Last_Operation_Status = true;

        public OrderRequest()
        { }

        public OrderRequest(Int32 nId, Int32 nCustomerId, string strAddressFrom, string strAddressTo, DateTime dtOrdTime)
        {
            this.nId = nId;
            this.nCustomerId = nCustomerId;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
        }

        public OrderRequest(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = true;

            if (oSqlDataReader.Read())
            {
                this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
                this.nCustomerId = (Int32)(oSqlDataReader.GetValue((int)Columns.CUSTOMER_ID));
                this.strAddressFrom = (oSqlDataReader.GetValue((int)Columns.ADDRESS_FROM)).ToString();
                this.strAddressTo = (oSqlDataReader.GetValue((int)Columns.ADDRESS_TO)).ToString();
                this.dtOrdTime = (DateTime)(oSqlDataReader.GetValue((int)Columns.ORD_TIME));
            }
            else
            {
                this.b_Last_Operation_Status = false;
            }
        }

    }

    class OrdReqCustName
    {
        // Enums
        public enum Columns
        {
            ID = 0, CUSTOMER_NAME = 1, ADDRESS_FROM = 2, ADDRESS_TO = 3, ORD_TIME = 4
        }

        // Table Fields
        public Int32 nId;
        public string strCustName;
        public string strAddressFrom;
        public string strAddressTo;
        public DateTime dtOrdTime; 

        public bool b_Last_Operation_Status = true;

        public OrdReqCustName()
        { }

        public OrdReqCustName(Int32 nId, string strCustName, string strAddressFrom, string strAddressTo, DateTime dtOrdTime)
        {
            this.nId = nId;
            this.strCustName = strCustName;
            this.strAddressFrom = strAddressFrom;
            this.strAddressTo = strAddressTo;
            this.dtOrdTime = dtOrdTime;
        }
    }

    class OrdReqCustNameReader
    {
        public List<OrdReqCustName> oOrdReqCustNamesList;

        public OrdReqCustNameReader(SqlDataReader oSqlDataReader)
        {
            oOrdReqCustNamesList = new List<OrdReqCustName>();
            this.Read_Many(oSqlDataReader);
        }

        public void Read_Many(SqlDataReader oSqlDataReader)
        {
            while (oSqlDataReader.Read())
            {
                OrdReqCustName oOrdReqCustName = new OrdReqCustName(
                        (Int32)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ID))
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.CUSTOMER_NAME)).ToString()
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_FROM)).ToString()
                        , (oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ADDRESS_TO)).ToString()
                        , (DateTime)(oSqlDataReader.GetValue((int)OrdReqCustName.Columns.ORD_TIME)));

                this.oOrdReqCustNamesList.Add(oOrdReqCustName);
            }
        }
    }
}
