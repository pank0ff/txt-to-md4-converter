// MDF4_SimpleWriter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mdf4.h"
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

struct DataRecord {
	std::string car_id;
	time_t timestamp;
	unsigned int rpm;
	unsigned int batt_temp;
	unsigned int engine_temp;
	unsigned int speed;
	unsigned int mileage;
	unsigned int estimated_mileage;
	unsigned int batt_charge_in_perc;
	unsigned int batt_charge_in_w;
	unsigned int cpu_temp;
	unsigned int gpu_temp;
	unsigned int c_in;
	unsigned int c_out;
	unsigned int v_in;
	unsigned int v_out;
	unsigned int solar_charge_temp;
	unsigned int drive_mode_state;
	unsigned int wire_charge_state;
	unsigned int solar_charge_state;
	unsigned int engine_error_state;
	unsigned int parking_brake_state;
	unsigned int hazard_state;
	unsigned int right_indicator_state;
	unsigned int high_beam_lights_state;
	unsigned int low_beam_lights_state;
	unsigned int position_lights_state;
	unsigned int left_indicator_state;
};

// Helper function to parse datetime string
time_t parseDatetime(const std::string& datetime) {
	struct tm tm = {};
	std::istringstream ss(datetime);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
	if (ss.fail()) {
		throw std::runtime_error("Failed to parse datetime: " + datetime);
	}
	return mktime(&tm);
}

// Function to parse the input file and return a vector of DataRecords
std::vector<DataRecord> parseInputFile(const std::string& filename) {
	std::vector<DataRecord> records;
	std::ifstream file(filename);
	std::string line;

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string datetime;
		std::string car_id;
		time_t timestamp;
		unsigned int rpm;
		unsigned int batt_temp;
		unsigned int engine_temp;
		unsigned int speed;
		unsigned int mileage;
		unsigned int estimated_mileage;
		unsigned int batt_charge_in_perc;
		unsigned int batt_charge_in_w;
		unsigned int cpu_temp;
		unsigned int gpu_temp;
		double c_in;
		double c_out;
		double v_in;
		double v_out;
		unsigned int solar_charge_temp;
		unsigned int drive_mode_state;
		unsigned int wire_charge_state;
		unsigned int solar_charge_state;
		unsigned int engine_error_state;
		unsigned int parking_brake_state;
		unsigned int hazard_state;
		unsigned int right_indicator_state;
		unsigned int high_beam_lights_state;
		unsigned int low_beam_lights_state;
		unsigned int position_lights_state;
		unsigned int left_indicator_state;

		std::stringstream ss(line);
		std::getline(ss, car_id, ',');
		std::getline(ss, datetime, ',');
		ss >> rpm;
		ss.ignore();
		ss >> batt_temp;
		ss.ignore();
		ss >> engine_temp;
		ss.ignore();
		ss >> speed;
		ss.ignore();
		ss >> mileage;
		ss.ignore();
		ss >> estimated_mileage;
		ss.ignore();
		ss >> batt_charge_in_perc;
		ss.ignore();
		ss >> batt_charge_in_w;
		ss.ignore();
		ss >> cpu_temp;
		ss.ignore();
		ss >> gpu_temp;
		ss.ignore();
		ss >> c_in;
		ss.ignore();
		ss >> c_out;
		ss.ignore();
		ss >> v_in;
		ss.ignore();
		ss >> v_out;
		ss.ignore();
		ss >> solar_charge_temp;
		ss.ignore();
		ss >> drive_mode_state;
		ss.ignore();
		ss >> wire_charge_state;
		ss.ignore();
		ss >> solar_charge_state;
		ss.ignore();
		ss >> engine_error_state;
		ss.ignore();
		ss >> parking_brake_state;
		ss.ignore();
		ss >> hazard_state;
		ss.ignore();
		ss >> right_indicator_state;
		ss.ignore();
		ss >> high_beam_lights_state;
		ss.ignore();
		ss >> low_beam_lights_state;
		ss.ignore();
		ss >> position_lights_state;
		ss.ignore();
		ss >> left_indicator_state;
		ss.ignore();

		DataRecord record;
		record.car_id = car_id;
		record.rpm = (unsigned int)rpm;
		record.batt_temp = batt_temp;
		record.engine_temp = engine_temp;
		record.speed = speed;
		record.mileage = mileage;
		record.estimated_mileage = estimated_mileage;
		record.batt_charge_in_perc = batt_charge_in_perc;
		record.batt_charge_in_w = batt_charge_in_w;
		record.cpu_temp = cpu_temp;
		record.gpu_temp = gpu_temp;
		record.c_in = (unsigned int)(c_in * 100);
		record.c_out = (unsigned int)(c_out * 100);
		record.v_in = (unsigned int)(v_in * 100);
		record.v_out = (unsigned int)(v_out * 100);
		record.solar_charge_temp = solar_charge_temp;
		record.drive_mode_state = drive_mode_state;
		record.wire_charge_state = wire_charge_state;
		record.solar_charge_state = solar_charge_state;
		record.engine_error_state = engine_error_state;
		record.parking_brake_state = parking_brake_state;
		record.hazard_state = hazard_state;
		record.right_indicator_state = right_indicator_state;
		record.high_beam_lights_state = high_beam_lights_state;
		record.low_beam_lights_state = low_beam_lights_state;
		record.position_lights_state = position_lights_state;
		record.left_indicator_state = left_indicator_state;
		record.timestamp = parseDatetime(datetime);

		records.push_back(record);

		std::cout << " " << record.rpm << " " << record.batt_temp << " " << record.engine_temp << " " << record.speed << " " << record.mileage << " " << record.estimated_mileage << " " << record.batt_charge_in_perc << " " << record.batt_charge_in_w << " " << record.cpu_temp << " " << record.gpu_temp << " " << record.c_in << " " << record.c_out << " " << record.v_in << " " << record.v_out << " " << record.solar_charge_temp << " " << record.drive_mode_state << " " << record.wire_charge_state << " " << record.solar_charge_state << " " << record.engine_error_state << " " << record.parking_brake_state << " " << record.hazard_state << " " << record.right_indicator_state << " " << record.high_beam_lights_state << " " << record.low_beam_lights_state << " " << record.position_lights_state << " " << record.left_indicator_state << std::endl;
	}

	return records;
}

int main(int argc, char* argv[])
{
	std::vector<DataRecord> dataRecords = parseInputFile("data.txt");

	// Find a reasonalbe time stamp:
	struct M_DATE now;
	memset(&now, 0, sizeof(M_DATE));
	time_t tt;
	time(&tt);
	now.time_ns = tt;
	now.time_ns *= 1000000000; // s -> ns

  // Create the Test-File
	int iVersion = 410; // v4.10
  MDF4File m4;

	if (m4.Create("../Test.mf4", "SimplWrtr", 410)) // v4.10
	{
    // There MUST be at least one FileHistory (FH)
    // which MUST have an MD-Block

		wchar_t *pszFileHistory =
			L"<FHcomment>"
			L"<TX>First Test of MDF4 library</TX>"
			L"<tool_id>toolblabla</tool_id>"
			L"<tool_vendor>MDZ Bührer&amp;Partner</tool_vendor>"
			L"<tool_version>0.1</tool_version>"
			L"</FHcomment>\0";


    M4MDBlock fc(pszFileHistory);
    // Create the FH-Block
    M4FHBlock *fh=new M4FHBlock();
    fh->Create(&m4);
    // add the comment
    fh->setComment(fc);
		fh->fh_time = now;
    // and add to the HD Block
    m4.addHistory(fh);

#if 0
    // AT Attachment block
    M4ATBlock *at=new M4ATBlock(&m4);
    at->EmbedFile(_T("C:\\filter.dat"),false,true);
    m4.addAttachment(at);
#endif

	  // UTF8-Test
    M4TXBlock Comment;
    // MD-Block XML test (the sequence is significant for MDF4 spec!)
		char *pszHeaderComment =
      "<HDcomment>"
			  "<TX>nothing special</TX>"
			  "<time_source>EtherCAT DC Reference Time</time_source>"
			  "<common_properties>"
				  "<e name=\"author\">Autor</e>"
					"<e name=\"department\">Department</e>"
					"<e name=\"project\">Project</e>"
					"<e name=\"subject\">Subject</e>"
				"</common_properties>"
			"</HDcomment>";
    M4MDBlock hdComment(pszHeaderComment);
    m4.setComment(hdComment);
		m4.GetHdr()->hd_time_class = 10; // external time source

		m4.setFileTime(now);

    // Create one DG with one CG with two CN's
    // Note: hd.addDataGroup, dg.addChannelGroup, cg.addChannel
    // must be called with an allocated object; they will be deleted
    // when the next object is added or in the destructor!
    M4DGBlock *dg=m4.addDataGroup(new M4DGBlock);
#ifdef WIN32
		dg->setComment(M4TXBlock("DataGroup Comment"));
#else
		M4TXBlock dgc("DataGroup Comment");
    dg->setComment(*(m4Block*)&dgc);
#endif
    M4CGBlock *cg=dg->addChannelGroup(new M4CGBlock);
#ifdef WIN32
		cg->setAcqName(*(m4Block*)&M4TXBlock("AcqName"));
#else
		M4TXBlock dgan("AcqName");
    cg->setAcqName(*(m4Block*)&dgan);
#endif
		cg->setRecordSize(76/*8+4*/,0);
	  dg->Save(true,true);

    // add the TIME channel
		M4CNBlock *cn=cg->addChannel(new M4CNBlock(CN_T_MASTER));
		cn->cn_sync_type |= CN_S_TIME;
		cg->Save(true,true);
		cn->setComment(*(m4Block*)&M4TXBlock("Time Channel"));
		cn->setName(*(m4Block*)&M4TXBlock("Timestamp"));
		//cn->setConversion(*(M4CCBlock*)&M4CCLinear(0.0031));
		cn->setLocation(CN_D_UINT_LE,0*8,8*8); // data type: uint 64
		M4TXBlock tx_time_unit("s");
		tx_time_unit.Create(&m4,3);
		tx_time_unit.Save(true,true);
		cn->setLink( m4CNRecord::cn_md_unit, tx_time_unit.m_At);
		cn->Save();

    // add the Value channel; CAUTION this will delete the cn!
		cn=cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock cnc("Value Channel");
		cn->setComment(*(M4CCBlock*)&cnc);
		M4TXBlock cnname("RPM");
		cn->setName(*(M4CCBlock*)&cnname);
		cn->setLocation(CN_D_UINT_LE,8*8,4*8); // data type: DWORD
		M4TXBlock rpm_value_unit("rpm");
		rpm_value_unit.Create(&m4,3);
		rpm_value_unit.Save(true,true);
		cn->setLink( m4CNRecord::cn_md_unit, rpm_value_unit.m_At);
		cn->Save();


		// add the Value channel; CAUTION this will delete the cn!
		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock bat_temp("Battery temperature");
		cn->setComment(*(M4CCBlock*)&bat_temp);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Battery temperature"));
		cn->setLocation(CN_D_UINT_LE, 12 * 8, 1 * 8); // data type: DWORD
		M4TXBlock bat_temp_value_unit("C");
		bat_temp_value_unit.Create(&m4, 0);
		bat_temp_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, bat_temp_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock eng_temp("Engine temperature");
		cn->setComment(*(M4CCBlock*)&eng_temp);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Engine temperature"));
		cn->setLocation(CN_D_UINT_LE, 13 * 8, 1 * 8); // data type: DWORD
		M4TXBlock eng_temp_value_unit("C");
		eng_temp_value_unit.Create(&m4, 0);
		eng_temp_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, eng_temp_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock speed("Speed");
		cn->setComment(*(M4CCBlock*)&speed);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Speed"));
		cn->setLocation(CN_D_UINT_LE, 14 * 8, 1 * 8); // data type: DWORD
		M4TXBlock speed_value_unit("km/h");
		speed_value_unit.Create(&m4, 0);
		speed_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, speed_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock mileage("Mileage");
		cn->setComment(*(M4CCBlock*)&mileage);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Mileage"));
		cn->setLocation(CN_D_UINT_LE, 15 * 8, 4 * 8); // data type: DWORD
		M4TXBlock mileage_value_unit("km");
		mileage_value_unit.Create(&m4, 3);
		mileage_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, mileage_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock est_mileage("Est Mileage");
		cn->setComment(*(M4CCBlock*)&est_mileage);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Est Mileage"));
		cn->setLocation(CN_D_UINT_LE, 19 * 8, 4 * 8); // data type: DWORD
		M4TXBlock est_mileage_value_unit("km");
		est_mileage_value_unit.Create(&m4, 3);
		est_mileage_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, est_mileage_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock batt_charge_in_perc("Battery charge in percentage");
		cn->setComment(*(M4CCBlock*)&batt_charge_in_perc);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Battery charge in percentage"));
		cn->setLocation(CN_D_UINT_LE, 23 * 8, 1 * 8); // data type: DWORD
		M4TXBlock batt_charge_in_perc_value_unit("%");
		batt_charge_in_perc_value_unit.Create(&m4, 0);
		batt_charge_in_perc_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, batt_charge_in_perc_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock batt_charge_in_w("Power for the day");
		cn->setComment(*(M4CCBlock*)&batt_charge_in_w);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Power for the day"));
		cn->setLocation(CN_D_UINT_LE, 24 * 8, 4 * 8); // data type: DWORD
		M4TXBlock batt_charge_in_w_value_unit("Wh");
		batt_charge_in_w_value_unit.Create(&m4, 3);
		batt_charge_in_w_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, batt_charge_in_w_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock cpu_temp("CPU temp");
		cn->setComment(*(M4CCBlock*)&cpu_temp);
		cn->setName(*(M4CCBlock*)&M4TXBlock("CPU temp"));
		cn->setLocation(CN_D_UINT_LE, 28 * 8, 1 * 8); // data type: DWORD
		M4TXBlock cpu_temp_value_unit("C");
		cpu_temp_value_unit.Create(&m4, 0);
		cpu_temp_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, cpu_temp_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock gpu_temp("GPU temp");
		cn->setComment(*(M4CCBlock*)&gpu_temp);
		cn->setName(*(M4CCBlock*)&M4TXBlock("GPU temp"));
		cn->setLocation(CN_D_UINT_LE, 29 * 8, 1 * 8); // data type: DWORD
		M4TXBlock gpu_temp_value_unit("C");
		gpu_temp_value_unit.Create(&m4, 0);
		gpu_temp_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, gpu_temp_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock c_in("Current input");
		cn->setComment(*(M4CCBlock*)&c_in);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Current input"));
		cn->setLocation(CN_D_UINT_LE, 30 * 8, 4 * 8); // data type: DWORD
		M4TXBlock c_in_value_unit("A");
		c_in_value_unit.Create(&m4, 3);
		c_in_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, c_in_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock c_out("Current output");
		cn->setComment(*(M4CCBlock*)&c_out);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Current output"));
		cn->setLocation(CN_D_UINT_LE, 34 * 8, 4 * 8); // data type: DWORD
		M4TXBlock c_out_value_unit("A");
		c_out_value_unit.Create(&m4, 3);
		c_out_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, c_out_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock v_in("Voltage input");
		cn->setComment(*(M4CCBlock*)&v_in);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Voltage input"));
		cn->setLocation(CN_D_UINT_LE, 38 * 8, 4 * 8); // data type: DWORD
		M4TXBlock v_in_value_unit("V");
		v_in_value_unit.Create(&m4, 3);
		v_in_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, v_in_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock v_output("Voltage output");
		cn->setComment(*(M4CCBlock*)&v_output);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Voltage output"));
		cn->setLocation(CN_D_UINT_LE, 42 * 8, 4 * 8); // data type: DWORD
		M4TXBlock v_output_value_unit("V");
		v_output_value_unit.Create(&m4, 3);
		v_output_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, v_output_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock solar_charge_temp("Solar charge temp");
		cn->setComment(*(M4CCBlock*)&solar_charge_temp);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Solar charge temp"));
		cn->setLocation(CN_D_UINT_LE, 46 * 8, 4 * 8); // data type: DWORD
		M4TXBlock solar_charge_temp_value_unit("C");
		solar_charge_temp_value_unit.Create(&m4, 3);
		solar_charge_temp_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, solar_charge_temp_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock drive_mode_state("Drive mode state");
		cn->setComment(*(M4CCBlock*)&drive_mode_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Drive mode state"));
		cn->setLocation(CN_D_UINT_LE, 50 * 8, 1 * 8); // data type: DWORD
		M4TXBlock drive_mode_state_value_unit("");
		drive_mode_state_value_unit.Create(&m4, 0);
		drive_mode_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, drive_mode_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock wire_charge_state("Wire charge state");
		cn->setComment(*(M4CCBlock*)&wire_charge_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Wire charge state"));
		cn->setLocation(CN_D_UINT_LE, 51 * 8, 1 * 8); // data type: DWORD
		M4TXBlock wire_charge_state_value_unit("");
		wire_charge_state_value_unit.Create(&m4, 0);
		wire_charge_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, wire_charge_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock solar_charge_state("Solar charge state");
		cn->setComment(*(M4CCBlock*)&solar_charge_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Solar charge state"));
		cn->setLocation(CN_D_UINT_LE, 52 * 8, 1 * 8); // data type: DWORD
		M4TXBlock solar_charge_state_value_unit("");
		solar_charge_state_value_unit.Create(&m4, 0);
		solar_charge_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, solar_charge_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock engine_error_state("Engine error state");
		cn->setComment(*(M4CCBlock*)&engine_error_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Solar charge state"));
		cn->setLocation(CN_D_UINT_LE, 53 * 8, 1 * 8); // data type: DWORD
		M4TXBlock engine_error_state_value_unit("");
		engine_error_state_value_unit.Create(&m4, 0);
		engine_error_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, engine_error_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock parking_brake_state("Parking brake state");
		cn->setComment(*(M4CCBlock*)&parking_brake_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Parking brake state"));
		cn->setLocation(CN_D_UINT_LE, 54 * 8, 1 * 8); // data type: DWORD
		M4TXBlock parking_brake_state_value_unit("");
		parking_brake_state_value_unit.Create(&m4, 0);
		parking_brake_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, parking_brake_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock hazard_state("Hazard state");
		cn->setComment(*(M4CCBlock*)&hazard_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Hazard state"));
		cn->setLocation(CN_D_UINT_LE, 55 * 8, 1 * 8); // data type: DWORD
		M4TXBlock hazard_state_value_unit("");
		hazard_state_value_unit.Create(&m4, 0);
		hazard_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, hazard_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock right_indicator_state("Right indicator state");
		cn->setComment(*(M4CCBlock*)&right_indicator_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Right indicator state"));
		cn->setLocation(CN_D_UINT_LE, 56 * 8, 1 * 8); // data type: DWORD
		M4TXBlock right_indicator_state_value_unit("");
		right_indicator_state_value_unit.Create(&m4, 0);
		right_indicator_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, right_indicator_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock high_beam_lights_state("High beam state");
		cn->setComment(*(M4CCBlock*)&high_beam_lights_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("High beam state"));
		cn->setLocation(CN_D_UINT_LE, 57 * 8, 1 * 8); // data type: DWORD
		M4TXBlock high_beam_lights_state_value_unit("");
		high_beam_lights_state_value_unit.Create(&m4, 0);
		high_beam_lights_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, high_beam_lights_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock low_beam_lights_state("Low beam state");
		cn->setComment(*(M4CCBlock*)&low_beam_lights_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Low beam state"));
		cn->setLocation(CN_D_UINT_LE, 58 * 8, 1 * 8); // data type: DWORD
		M4TXBlock low_beam_lights_state_value_unit("");
		low_beam_lights_state_value_unit.Create(&m4, 0);
		low_beam_lights_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, low_beam_lights_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock position_lights_state("Position lights state");
		cn->setComment(*(M4CCBlock*)&position_lights_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Position lights state"));
		cn->setLocation(CN_D_UINT_LE, 59 * 8, 1 * 8); // data type: DWORD
		M4TXBlock position_lights_state_value_unit("");
		position_lights_state_value_unit.Create(&m4, 0);
		position_lights_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, position_lights_state_value_unit.m_At);
		cn->Save();

		cn = cg->addChannel(new M4CNBlock(CN_T_FIXEDLEN));
		M4TXBlock left_indicator_state("Left indicator state");
		cn->setComment(*(M4CCBlock*)&left_indicator_state);
		cn->setName(*(M4CCBlock*)&M4TXBlock("Left indicator state"));
		cn->setLocation(CN_D_UINT_LE, 60 * 8, 1 * 8); // data type: DWORD
		M4TXBlock left_indicator_state_value_unit("");
		left_indicator_state_value_unit.Create(&m4, 0);
		left_indicator_state_value_unit.Save(true, true);
		cn->setLink(m4CNRecord::cn_md_unit, left_indicator_state_value_unit.m_At);
		cn->Save();

		M_UINT32 uiDataRecordSize = cg->cg_data_bytes + dg->dg_rec_id_size; // + rec id
		// the following code is crucial for the effectiveness of storing/reading the data:
		M_UINT32 uiNoOfRecords = dataRecords.size();; // No. of record per block
		// A data block should be large enough to be read effectively, but small enough to avoid empty space.
		M_UINT32 uiDataBlockSize = uiDataRecordSize * uiNoOfRecords/2; // a good size for large file is 5 MB per block
		M_UINT32 rec_id_size = dg->dg_rec_id_size;

		m4.addRecordCount(cg,1); // Group 1

		m4DataStream *out = NULL; // 4.0 normal blocks
		m4DZStream   *outDZ = NULL; // 4.10 compressed blocks
		if (iVersion == 410)
		{
			outDZ = dg->DZWriteStream(uiDataBlockSize, uiDataRecordSize, 5);
			out = outDZ;
		}
		else
			out = dg->WriteStream(uiDataBlockSize);
		cg->Save(true,true);
		m4.Prepare();

		M_UINT8 *pRecord = (M_UINT8*)calloc(uiDataRecordSize,1);

		
		for (M_UINT32 i=1; i<=uiNoOfRecords; i++)
		{
			M_UINT8 *p = pRecord;
			if (rec_id_size)
			{
				*p = (M_UINT8)1; // record id
				p+=rec_id_size;
			}
			*(M_UINT64*)p = (M_UINT64)dataRecords[i - 1].timestamp; // time
			p += sizeof(M_UINT64);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].rpm; // Value
			p += sizeof(M_UINT32);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].batt_temp; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].engine_temp; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].speed; // Value
			p += sizeof(M_UINT8);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].mileage; // Value
			p += sizeof(M_UINT32);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].estimated_mileage; // Value
			p += sizeof(M_UINT32);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].batt_charge_in_perc; // Value
			p += sizeof(M_UINT8);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].batt_charge_in_w; // Value
			p += sizeof(M_UINT32);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].cpu_temp; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].gpu_temp; // Value
			p += sizeof(M_UINT8);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].c_in; // Value
			p += sizeof(M_UINT32);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].c_out; // Value
			p += sizeof(M_UINT32);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].v_in; // Value
			p += sizeof(M_UINT32);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].v_out; // Value
			p += sizeof(M_UINT32);
			*(M_UINT32*)p = (M_UINT32)dataRecords[i - 1].solar_charge_temp; // Value
			p += sizeof(M_UINT32);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].drive_mode_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].wire_charge_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].solar_charge_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].engine_error_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].parking_brake_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].hazard_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].right_indicator_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].high_beam_lights_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].low_beam_lights_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].position_lights_state; // Value
			p += sizeof(M_UINT8);
			*(M_UINT8*)p = (M_UINT8)dataRecords[i - 1].left_indicator_state; // Value
			//p += sizeof(DWORD); // no invalid bytes used here

			out->Write(uiDataRecordSize,pRecord);	// append
		}

		out->AddRecords(uiNoOfRecords,1); // group 1

		//free(pRecord);
		out->Flush();
		out->Close();
	  delete out;

    m4.Save();
    m4.Close();
  }
  return 0;
}

