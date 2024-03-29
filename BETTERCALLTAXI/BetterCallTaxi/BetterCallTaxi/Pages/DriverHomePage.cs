﻿using BetterCallTaxi.Models;
using BetterCallTaxi.Pages;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class DriverHomePage : Form
    {
        private Customer recCustomer;
        private GroupBox Welcome_Driver;
        private Button Logout_Driver_Button;
        private Button Profile_Driver_Button;
        private DataGridView Driver_Home_Order_Requests;
        private BindingSource betterCallTaxiOrderRequestsBindingSource;
        private System.ComponentModel.IContainer components;
        private BetterCallTaxi_Order_Requests betterCallTaxi_Order_Requests;
        private Button Driver_Home_Take_Request_Btn;
        private Button Driver_Profile_View_Button;
        private Driver recDriver;
        private Label Driver_Home_Page_View_Header;
        private bool bOrdReq; // true - зареждаме ORDER_REQUESTS, false - зареждаме ORDERS

        public DriverHomePage(Customer recCustomer, Driver recDriver)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;
            this.recDriver = recDriver;
            this.Welcome_Driver.Text = String.Format(this.Welcome_Driver.Text, recCustomer.strName);
            this.Driver_Home_Order_Requests.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            this.Driver_Home_Order_Requests.MultiSelect = false;
        }

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DriverHomePage));
            this.Welcome_Driver = new System.Windows.Forms.GroupBox();
            this.Logout_Driver_Button = new System.Windows.Forms.Button();
            this.Profile_Driver_Button = new System.Windows.Forms.Button();
            this.Driver_Home_Order_Requests = new System.Windows.Forms.DataGridView();
            this.betterCallTaxiOrderRequestsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.betterCallTaxi_Order_Requests = new BetterCallTaxi.BetterCallTaxi_Order_Requests();
            this.Driver_Home_Take_Request_Btn = new System.Windows.Forms.Button();
            this.Driver_Profile_View_Button = new System.Windows.Forms.Button();
            this.Driver_Home_Page_View_Header = new System.Windows.Forms.Label();
            this.Welcome_Driver.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Driver_Home_Order_Requests)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.betterCallTaxiOrderRequestsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.betterCallTaxi_Order_Requests)).BeginInit();
            this.SuspendLayout();
            // 
            // Welcome_Driver
            // 
            this.Welcome_Driver.BackColor = System.Drawing.Color.Transparent;
            this.Welcome_Driver.Controls.Add(this.Logout_Driver_Button);
            this.Welcome_Driver.Controls.Add(this.Profile_Driver_Button);
            this.Welcome_Driver.Location = new System.Drawing.Point(13, 13);
            this.Welcome_Driver.Name = "Welcome_Driver";
            this.Welcome_Driver.Size = new System.Drawing.Size(183, 114);
            this.Welcome_Driver.TabIndex = 0;
            this.Welcome_Driver.TabStop = false;
            this.Welcome_Driver.Text = "Welcome, {0}!";
            // 
            // Logout_Driver_Button
            // 
            this.Logout_Driver_Button.Location = new System.Drawing.Point(7, 65);
            this.Logout_Driver_Button.Name = "Logout_Driver_Button";
            this.Logout_Driver_Button.Size = new System.Drawing.Size(166, 36);
            this.Logout_Driver_Button.TabIndex = 1;
            this.Logout_Driver_Button.Text = "Logout";
            this.Logout_Driver_Button.UseVisualStyleBackColor = true;
            this.Logout_Driver_Button.Click += new System.EventHandler(this.Logout_Driver_Button_Click);
            // 
            // Profile_Driver_Button
            // 
            this.Profile_Driver_Button.Location = new System.Drawing.Point(7, 22);
            this.Profile_Driver_Button.Name = "Profile_Driver_Button";
            this.Profile_Driver_Button.Size = new System.Drawing.Size(166, 36);
            this.Profile_Driver_Button.TabIndex = 0;
            this.Profile_Driver_Button.Text = "Profile";
            this.Profile_Driver_Button.UseVisualStyleBackColor = true;
            this.Profile_Driver_Button.Click += new System.EventHandler(this.Profile_Driver_Button_Click);
            // 
            // Driver_Home_Order_Requests
            // 
            this.Driver_Home_Order_Requests.AllowUserToAddRows = false;
            this.Driver_Home_Order_Requests.AllowUserToDeleteRows = false;
            this.Driver_Home_Order_Requests.AllowUserToOrderColumns = true;
            this.Driver_Home_Order_Requests.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Driver_Home_Order_Requests.Location = new System.Drawing.Point(362, 284);
            this.Driver_Home_Order_Requests.Name = "Driver_Home_Order_Requests";
            this.Driver_Home_Order_Requests.ReadOnly = true;
            this.Driver_Home_Order_Requests.RowTemplate.Height = 24;
            this.Driver_Home_Order_Requests.Size = new System.Drawing.Size(593, 353);
            this.Driver_Home_Order_Requests.TabIndex = 1;
            // 
            // betterCallTaxiOrderRequestsBindingSource
            // 
            this.betterCallTaxiOrderRequestsBindingSource.DataSource = this.betterCallTaxi_Order_Requests;
            this.betterCallTaxiOrderRequestsBindingSource.Position = 0;
            // 
            // betterCallTaxi_Order_Requests
            // 
            this.betterCallTaxi_Order_Requests.DataSetName = "BetterCallTaxi_Order_Requests";
            this.betterCallTaxi_Order_Requests.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // Driver_Home_Take_Request_Btn
            // 
            this.Driver_Home_Take_Request_Btn.Location = new System.Drawing.Point(763, 236);
            this.Driver_Home_Take_Request_Btn.Name = "Driver_Home_Take_Request_Btn";
            this.Driver_Home_Take_Request_Btn.Size = new System.Drawing.Size(188, 42);
            this.Driver_Home_Take_Request_Btn.TabIndex = 2;
            this.Driver_Home_Take_Request_Btn.Text = "Take Customer Order";
            this.Driver_Home_Take_Request_Btn.UseVisualStyleBackColor = true;
            this.Driver_Home_Take_Request_Btn.Click += new System.EventHandler(this.Driver_Home_Take_Request_Btn_Click);
            // 
            // Driver_Profile_View_Button
            // 
            this.Driver_Profile_View_Button.Location = new System.Drawing.Point(565, 236);
            this.Driver_Profile_View_Button.Name = "Driver_Profile_View_Button";
            this.Driver_Profile_View_Button.Size = new System.Drawing.Size(192, 42);
            this.Driver_Profile_View_Button.TabIndex = 3;
            this.Driver_Profile_View_Button.Text = "View my Orders";
            this.Driver_Profile_View_Button.UseVisualStyleBackColor = true;
            this.Driver_Profile_View_Button.Click += new System.EventHandler(this.Driver_Profile_View_Button_Click);
            // 
            // Driver_Home_Page_View_Header
            // 
            this.Driver_Home_Page_View_Header.AutoSize = true;
            this.Driver_Home_Page_View_Header.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.Driver_Home_Page_View_Header.Location = new System.Drawing.Point(362, 260);
            this.Driver_Home_Page_View_Header.Name = "Driver_Home_Page_View_Header";
            this.Driver_Home_Page_View_Header.Size = new System.Drawing.Size(86, 17);
            this.Driver_Home_Page_View_Header.TabIndex = 4;
            this.Driver_Home_Page_View_Header.Text = "View header";
            // 
            // DriverHomePage
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(963, 642);
            this.Controls.Add(this.Driver_Home_Page_View_Header);
            this.Controls.Add(this.Driver_Profile_View_Button);
            this.Controls.Add(this.Driver_Home_Take_Request_Btn);
            this.Controls.Add(this.Driver_Home_Order_Requests);
            this.Controls.Add(this.Welcome_Driver);
            this.Name = "DriverHomePage";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Load += new System.EventHandler(this.DriverHomePage_Load);
            this.Welcome_Driver.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.Driver_Home_Order_Requests)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.betterCallTaxiOrderRequestsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.betterCallTaxi_Order_Requests)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Logout_Driver_Button_Click(object sender, EventArgs e)
        {
            LogoutPopUp oDlg = new LogoutPopUp();
            DialogResult oDlgResult = oDlg.ShowDialog();
            if (oDlgResult == DialogResult.OK)
            {
                this.DialogResult = DialogResult.Cancel;
                this.Close();
            }
        }

        private void Profile_Driver_Button_Click(object sender, EventArgs e)
        { 
            // Крием Home страницата
            this.Hide();

            // Показваме Profile страницата
            ProfileDialog oProfileDialog = new ProfileDialog(recCustomer);
            oProfileDialog.ShowDialog();

            // За всеки случай ако е променян потребителят, го взимаме наново от базата
            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader =
                oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_ID, this.recCustomer.nId));

            // Записваме си го при нас
            this.recCustomer = new Customer(oSqlDataReader);
            this.Welcome_Driver.Text = String.Format(GlobalConstants.WELCOME_USER, this.recCustomer.strName);

            // Да не забравим да затворим след нас
            oSqlDataReader.Close();

            // Показваме обратно Home страницата
            this.Show();
        }

        private void DriverHomePage_Load(object sender, EventArgs e)
        {
            this.bOrdReq = true; // като за начало да зареждаме order requests
            this.Load_Ord_Req();
        }

        private void Load_Ord_Req()
        {
            this.Driver_Home_Page_View_Header.Text = GlobalConstants.ALL_ORDER_REQUESTS;
            this.Driver_Home_Take_Request_Btn.Text = GlobalConstants.TAKE_ORDER;
            this.Driver_Profile_View_Button.Text = GlobalConstants.VIEW_MY_ORDERS;
            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_ALL_ORDER_REQUESTS));
            OrderRequestsReader oOrderRequestsReader = new OrderRequestsReader(oSqlDataReader);
            oSqlDataReader.Close();

            DataTable oDataTable = new DataTable() { Locale = CultureInfo.InvariantCulture };
            oDataTable.Columns.Add(GlobalConstants.ID, typeof(Int32));
            oDataTable.Columns.Add(GlobalConstants.CUSTOMER_ID, typeof(Int32));
            oDataTable.Columns.Add(GlobalConstants.ADDRESS_FROM, typeof(string));
            oDataTable.Columns.Add(GlobalConstants.DESTINATION_ADDRESS, typeof(string));
            oDataTable.Columns.Add(GlobalConstants.ORD_TIME, typeof(string));

            foreach (OrderRequest recOrdReq in oOrderRequestsReader.oOrderRequests)
            {
                oDataTable.Rows.Add(recOrdReq.nId, recOrdReq.nCustomerId, recOrdReq.strAddressFrom, recOrdReq.strAddressTo,
                    recOrdReq.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT));
            }

            this.Driver_Home_Order_Requests.DataSource = oDataTable;
        }

        private void Driver_Home_Take_Request_Btn_Click(object sender, EventArgs e)
        {
            if (bOrdReq)
                this.TakeCustomerOrder();
            else
                this.MarkCustomerOrderAsCompleted();
        }

        private void TakeCustomerOrder()
        {
            // отваряме диалога за потвърждаване на приемане на поръчка
            int nOrdReqId = Int32.Parse(this.Driver_Home_Order_Requests.SelectedCells[0].Value.ToString());
            OrderRequestClaim oDlg = new OrderRequestClaim(nOrdReqId);
            DialogResult oDlgRes = oDlg.ShowDialog();

            if (oDlgRes == DialogResult.OK)
            {
                // взимаме код на таксито през шофьора
                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.SELECT_CAR_KOD_TAXI_BY_DRIVER_ID, this.recDriver.nId), true);
                oSqlDataReader.Read();
                int nKodTaxi = (Int32)(oSqlDataReader.GetValue(0));

                // формираме си поръчка
                Order recOrder = new Order(
                    0, nKodTaxi
                    , oDlg.oOrdReqCustNameAndId.oOrdReqCustName.strAddressFrom
                    , oDlg.oOrdReqCustNameAndId.oOrdReqCustName.strAddressTo
                    , oDlg.oOrdReqCustNameAndId.oOrdReqCustName.dtOrdTime
                    , new TimeSpan(), 0, 0, oDlg.oOrdReqCustNameAndId.nCustId, false);

                // добавяме поръчката в ORDERS
                oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.INSERT_ORDER,
                    nKodTaxi, recOrder.strAddressFrom, recOrder.strAddressTo, recOrder.dtOrdTime,
                    recOrder.nCustomerId, recOrder.bIsDone ? 1 : 0), true);

                // трием заявката за поръчка от ORDER_REQUESTS
                oSqlDataReader = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.DELETE_ORDER_REQUEST, nOrdReqId), true);

                // трием заявката и от datagridview-то, зададено е multiselect false така че трябва да изтрие един ред 
                foreach (DataGridViewRow row in this.Driver_Home_Order_Requests.SelectedRows)
                {
                    this.Driver_Home_Order_Requests.Rows.RemoveAt(row.Index);
                }

                // обновяваме статуса на шофьора
                oSqlDataReader = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.UPDATE_DRIVER_STATUS, 0 /*busy*/, this.recDriver.nId), true);
            }
        }

        private void MarkCustomerOrderAsCompleted()
        {
            // взимаме си ID на ORDER от view-то
            int nNumOrd = Int32.Parse(this.Driver_Home_Order_Requests.SelectedCells[0].Value.ToString());

            // четем ORDER от базата
            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_ORDER, nNumOrd), true);
            Order recOrder = new Order(oSqlDataReader);
            oSqlDataReader.Close();

            // отваряме диалога за потвърждаване на поръчка за готова
            MarkOrderAsCompleted oDlg = new MarkOrderAsCompleted(recOrder);
            DialogResult oDlgResult = oDlg.ShowDialog();

            if(oDlgResult == DialogResult.OK)
            {
                // редактираме поръчката в базата
                oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.UPDATE_ORDER_MARK_COMPLETED
                    , oDlg.recOrder.tDrivingTime.ToString(), oDlg.recOrder.dDistance, oDlg.recOrder.dFare, oDlg.recOrder.nNumOrd)
                    , true, true);

                // редактираме DRIVERS като увеличаваме броячите му
                oDatabaseManager.ExecuteQuery(String.Format(GlobalConstants.UPDATE_DRIVER_AFTER_ORDER_COMPLETION
                    , oDlg.recOrder.dFare, this.recDriver.nId)
                    , true, true);

                // трием поръчката и от datagridview-то, зададено е multiselect false така че трябва да изтрие един ред 
                foreach (DataGridViewRow row in this.Driver_Home_Order_Requests.SelectedRows)
                {
                    this.Driver_Home_Order_Requests.Rows.RemoveAt(row.Index);
                }

                // ако няма поръчки, шофьорът вече не е busy и го редактираме на available
                if (this.Driver_Home_Order_Requests.RowCount == 0)
                {
                    // обновяваме статуса на шофьора
                    oSqlDataReader = oDatabaseManager.ExecuteQuery(
                        String.Format(GlobalConstants.UPDATE_DRIVER_STATUS, 1 /*available*/, this.recDriver.nId), true);
                }
            }

            oDlg.Close();
        }

        private void Driver_Profile_View_Button_Click(object sender, EventArgs e)
        {
            this.bOrdReq = !this.bOrdReq;

            if (this.bOrdReq)
                this.Load_Ord_Req();
            else
                this.Load_Ord();
        }

        private void Load_Ord()
        {
            this.Driver_Home_Page_View_Header.Text = GlobalConstants.MY_CURRENT_ORDERS;
            this.Driver_Profile_View_Button.Text = GlobalConstants.VIEW_ORDER_REQUESTS;
            this.Driver_Home_Take_Request_Btn.Text = GlobalConstants.COMPLETE_ORDER;

            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_ACTIVE_ORDERS_BY_DRIVER, this.recDriver.nId));
            ActiveOrderDataReader oActiveOrderDataReader = new ActiveOrderDataReader(oSqlDataReader);
            oSqlDataReader.Close();

            DataTable oDataTable = new DataTable() { Locale = CultureInfo.InvariantCulture };
            oDataTable.Columns.Add(GlobalConstants.ID, typeof(Int32));
            oDataTable.Columns.Add(GlobalConstants.ADDRESS_FROM, typeof(string));
            oDataTable.Columns.Add(GlobalConstants.DESTINATION_ADDRESS, typeof(string));
            oDataTable.Columns.Add(GlobalConstants.ORD_TIME, typeof(DateTime));
            oDataTable.Columns.Add(GlobalConstants.IS_DONE, typeof(string));

            foreach (ActiveOrderData oActiveOrderData in oActiveOrderDataReader.oActiveOrderDataList)
            {
                oDataTable.Rows.Add(oActiveOrderData.nNumOrd, oActiveOrderData.strAddressFrom, oActiveOrderData.strAddressTo
                    , oActiveOrderData.dtOrdTime, oActiveOrderData.bIsDone ? GlobalConstants.ORDER_DONE : GlobalConstants.ORDER_ACTIVE);
            }

            this.Driver_Home_Order_Requests.DataSource = oDataTable;
        }

    }
}
