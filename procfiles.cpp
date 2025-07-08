#include "procfiles.h"
#include "QDateTime"
bool selfNumber(QString str)
{
    unsigned long number= str.toLong();
    if ( number >= 78795131790 and number <= 78795131799)
        return true;

    if ( number >= 78795131801 and number <= 78795131899)
        return true;

    if ( number >= 78795131901 and number <= 78795131999)
        return true;

    if ( number >= 78795132001 and number <= 78795132099)
        return true;

    if ( number >= 78795132101 and number <= 78795132199)
        return true;

    if ( number >= 78795132101 and number <= 78795132199)
        return true;

    if ( number >= 78795132201 and number <= 78795132289)
        return true;

    if ( number >= 78795135501 and number <= 78795135599)
        return true;

    return false;
}

void procFile(QString pathToInput, QString PathToOutput)
{
    QVector<QStringList> allString;
    QDateTime curTime = QDateTime::currentDateTime();

    QFile file(pathToInput);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qCritical() << "Не удалось открыть файл:" << pathToInput << file.errorString();
        }

    QTextStream in(&file);
    while (!in.atEnd()) {
           QString line = in.readLine();
           //qDebug() << line;
           QStringList fields = line.split(';');
           allString.push_back(fields);
           /* Пример вывода по полям
           for (int i = 0; i < fields.size(); ++i) {
               qDebug() << "Поле" << i << ":" << fields.at(i).trimmed();
           }
           qDebug() << "-----"; // Разделитель строк
           */
       }
    QString nameFinalFiles = PathToOutput + "/cdr_v3_" +
            QString::number(curTime.date().year()) + "_" +
            QString::number(curTime.date().month()) + "_" +
            QString::number(curTime.date().day()) + "_" +
            QString::number(curTime.time().hour()) + "_" +
            QString::number(curTime.time().minute()) + "_" +
            QString::number(curTime.time().second()) + ".csv";
    QFile newFile(nameFinalFiles);
    QStringList head
    {
                     "telco_id",
                     "begin_connection_time",
                     "duration",
                     "call_type_id",
                     "supplement_service_id",
                     "in_abonent_type",
                     "out_abonent_type",
                     "switch_id",
                     "inbound_bunch_type",
                     "inbound_bunch_gsm",
                     "inbound_bunch_mac",
                     "inbound_bunch_vpi",
                     "inbound_bunch_vci",
                     "outbound_bunch_type",
                     "outbound_bunch_gsm",
                     "outbound_bunch_mac",
                     "outbound_bunch_vpi",
                     "outbound_bunch_vci",
                     "term_cause",
                     "phone_card_number",
                     "dialed_digits",
                     "forwarding_identifier",
                     "border_switch_id",
                     "roaming_partner_id",
                     "message",
                     "in_identifier_type",
                     "in_pstn_directory_number",
                     "in_pstn_internal_number",
                     "in_gsm_directory_number",
                     "in_gsm_imsi",
                     "in_gsm_imei",
                     "in_gsm_icc",
                     "in_cdma_directory_number",
                     "in_cdma_imsi",
                     "in_cdma_icc",
                     "in_cdma_esn",
                     "in_cdma_min",
                     "in_voip_ip_address",
                     "in_voip_originator_name",
                     "in_voip_calling_number",
                     "in_begin_location_type",
                     "in_begin_location_mobile_lac",
                     "in_begin_location_mobile_cell",
                     "in_begin_location_mobile_ta",
                     "in_begin_location_wireless_cell",
                     "in_begin_location_wireless_mac",
                     "in_begin_location_geolocation_latitude_grade",
                     "in_begin_location_geolocation_longitude_grade",
                     "in_begin_location_geolocation_projection_type",
                     "in_begin_location_iplocation_ip_address",
                     "in_begin_location_iplocation_ip_port",
                     "in_end_location_type",
                     "in_end_location_mobile_lac",
                     "in_end_location_mobile_cell",
                     "in_end_location_mobile_ta",
                     "in_end_location_wireless_cell",
                     "in_end_location_wireless_mac",
                     "in_end_location_geolocation_latitude_grade",
                     "in_end_location_geolocation_longitude_grade",
                     "in_end_location_geolocation_projection_type",
                     "in_end_location_iplocation_ip_address",
                     "in_end_location_iplocation_ip_port",
                     "out_identifier_type",
                     "out_pstn_directory_number",
                     "out_pstn_internal_number",
                     "out_gsm_directory_number",
                     "out_gsm_imsi",
                     "out_gsm_imei",
                     "out_gsm_icc",
                     "out_cdma_directory_number",
                     "out_cdma_imsi",
                     "out_cdma_icc",
                     "out_cdma_esn",
                     "out_cdma_min",
                     "out_voip_ip_address",
                     "out_voip_originator_name",
                     "out_voip_calling_number",
                     "out_begin_location_type",
                     "out_begin_location_mobile_lac",
                     "out_begin_location_mobile_cell",
                     "out_begin_location_mobile_ta",
                     "out_begin_location_wireless_cell",
                     "out_begin_location_wireless_mac",
                     "out_begin_location_geolocation_latitude_grade",
                     "out_begin_location_geolocation_longitude_grade",
                     "out_begin_location_geolocation_projection_type",
                     "out_begin_location_iplocation_ip_address",
                     "out_begin_location_iplocation_ip_port",
                     "out_end_location_type",
                     "out_end_location_mobile_lac",
                     "out_end_location_mobile_cell",
                     "out_end_location_mobile_ta",
                     "out_end_location_wireless_cell",
                     "out_end_location_wireless_mac",
                     "out_end_location_geolocation_latitude_grade",
                     "out_end_location_geolocation_longitude_grade",
                     "out_end_location_geolocation_projection_type",
                     "out_end_location_iplocation_ip_address",
                     "out_end_location_iplocation_ip_port",
                     "data_content_id",
                     "ss7_opc",
                     "ss7_dpc",
                    };
    bool isFirst = false;

    if (!newFile.exists())
    {
        isFirst = true;
    }

    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
    {
        qCritical() << "Не удалось открыть файл: " << nameFinalFiles << newFile.errorString();
    }

    QTextStream out(&newFile);
    if (isFirst)
    {
        out << head.join(",");
        Qt::endl(out);
    }


    //qDebug() << allString[0].size();




    for (const QStringList el : allString)
    {
        bool isError = false;
        QVector<QString> row;
        row.resize(102);

        row[0] = "0";
        row[1] = el[1];
        row[2] = el[3];
        row[4] = "0";
        row[7] = "0";
        row[8] = "0";
        row[13] = "0";

        row[18] = el[4];
        row[20] = el[11];
        row[22] = "0";
        row[25] = "1";
        row[26] = el[7];
        //row[27] = el[7];
        row[62] = "1";
        row[63] = el[11];



        if (el[6]=="sip-user" or el[6]=="trunk-SIP")
            row[3] = "1";
        if (el[6] == "trunk-SS7")
            row[3] = "2";


        if (selfNumber(el[7]))
        {
            row[5] = "0";
        }
        else
        {
            row[5] = "1";
        }

        if (selfNumber(el[11]))
        {
            row[6] = "0";
        }
        else
        {
            row[6] = "1";
        }

        row[14] = "6";
        if (el[18] == "rostelecom")
            row[14]="1";
        if (el[18] == "beeline")
            row[14]="2";
        if (el[18] == "megafon")
            row[14]="3";
        if (el[18] == "trunkgroup-vpbx")
            row[14]="4";
        if (el[18] == "trunkgroup-aster")
            row[14]="5";

        row[9] = "6";
        if (el[19] == "rostelecom")
            row[9]="1";
        if (el[19] == "beeline")
            row[9]="2";
        if (el[19] == "megafon")
            row[9]="3";
        if (el[19] == "trunkgroup-vpbx")
            row[9]="4";
        if (el[19] == "trunkgroup-aster")
            row[9]="5";


        /*
        if (el[6]=="sip-user" or el[6]=="trunk-SIP")
            row[5] = "0";
        if (el[6]=="trunk-SS7" )
            row[5] = "1";

        if(el[10] == "")
        {
            isError = true;
        }
        if (el[10]=="sip-user" or el[10] == "trunk-SIP" or el[10] == "user-serviced")
        {
            row[6]="0";
        }
        if (el[10]=="trunk-SS7" )
        {
            row[6]="1";
        }

        if (el[6] == "trunk-SS7")
        {
            row[25]="1";
        }

        if (el[6] == "sip-user" or el[6] == "trunk-SIP")
        {
            row[25]="5";
        }

        if(el[6] == "sip-user" or el[6] == "trunk-SIP")
        {
            row[26] = el[8];
        }

        if (el[6] == "trunk-SS7")
        {
            row[37] = el[7];
        }

        if (el[10] =="sip-user" or el[10]=="trunk-SIP")
        {
            row[63] = el[9];
        }

        if (el[10] =="trunk-SS7")
        {
            row[74] = el[12];
        }
        */


        if(!isError)
        {
            out << row.toList().join(",");
            Qt::endl(out);
        }

    }

    newFile.close();




}
