create view GUNLUK_SIPARISLER_VIEW
as select * from SALES_ORDER
where S_order_date = cast(getdate()as date);