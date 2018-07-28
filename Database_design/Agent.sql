 Create table AGENT(
     AGT_NUM char(3) Primary Key,
     AGT_LNAME char(25) NOT NULL,
     AGT_FNAME char(20) NOT NULL,
     AGT_AREACODE char(3),
     AGT_PHONE char(7));
INSERT INTO AGENT VALUES ('5','Andrews','Mark','416','1233456');
INSERT INTO AGENT VALUES ('10','Chen','Terry','250','3334059');
INSERT INTO AGENT VALUES ('15','Dasilva','Lila','416','2345837');
INSERT INTO AGENT VALUES ('20','Edwards','George','416','4445959');
INSERT INTO AGENT VALUES ('25','Eustace','Gina','519','9488494');