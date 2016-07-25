#include <stdio.h>
#include <stdlib.h>
#include "RTMAdapter-1.0/manager_adapter.h"
#include "RTMAdapter-1.0/coil_adapter.h"

#include "BasicDataType-1.0/BasicDataType.h"



RTC_t rtc;


// -------------- RTC Functions -------------------
int initialize(RTC_t rtc);
int on_activated(int ec_id);
int on_deactivated(int ec_id);
int on_execute(int ec_id);

// -------------- Module Initialization -------------
void my_module_init(Manager_t m) {
	Manager_RTMAdapter_init(m);
	if (rtc = Manager_createComponent(m, "RTMAdapter") == RESULT_INVALID_RTC) {
		printf("#Error. Invalid RTC ID.\n");
		return;
	}

	initialize(rtc);

	RTC_onActivated_listen(rtc, on_activated);
	RTC_onDeactivated_listen(rtc, on_deactivated);
	RTC_onExecute_listen(rtc, on_execute);
}

// ------------ Main Function --------------------
int main(int argc, char* argv[]) {
	Manager_t m = Manager_initManager(argc, argv);
	Manager_init(m, argc, argv);
	Manager_setModuleInitProc(m, my_module_init);
	Manager_activateManager(m);
	Manager_runManager(m, 0);

	return 0;
}


//------------------------ RTC Code ---------------------------

DataType_t _d_in_RTC_TimedLong, _d_out_RTC_TimedLong;
Port_t _in_RTC_TimedLongIn, _out_RTC_TimedLongOut;

DataType_t _d_in_RTC_TimedDouble, _d_out_RTC_TimedDouble;
Port_t _in_RTC_TimedDoubleIn, _out_RTC_TimedDoubleOut;

DataType_t _d_in_RTC_TimedString, _d_out_RTC_TimedString;
Port_t _in_RTC_TimedStringIn, _out_RTC_TimedStringOut;


DataType_t _d_in_RTC_TimedLongSeq, _d_out_RTC_TimedLongSeq;
Port_t _in_RTC_TimedLongSeqIn, _out_RTC_TimedLongSeqOut;

DataType_t _d_in_RTC_TimedDoubleSeq, _d_out_RTC_TimedDoubleSeq;
Port_t _in_RTC_TimedDoubleSeqIn, _out_RTC_TimedDoubleSeqOut;

/**
* Initialize RTC.
* on_initialize can not be captured in current version.
* Please initialize RTC in my_module_init proc.
*/
int initialize(RTC_t rtc) {
	_d_in_RTC_TimedLong = RTC_TimedLong_create();
	_in_RTC_TimedLongIn = InPort_RTC_TimedLong_create("RTC_TimedLong_in", _d_in_RTC_TimedLong);
	if (RTC_addInPort(rtc, "RTC_TimedLong_in", _in_RTC_TimedLongIn) < 0) {
		return -1;
	}

	_d_out_RTC_TimedLong = RTC_TimedLong_create();
	_out_RTC_TimedLongOut = OutPort_RTC_TimedLong_create("RTC_TimedLong_out", _d_out_RTC_TimedLong);
	if (RTC_addOutPort(rtc, "RTC_TimedLong_out", _out_RTC_TimedLongOut) < 0) {
		return -1;
	}

	_d_in_RTC_TimedDouble = RTC_TimedDouble_create();
	_in_RTC_TimedDoubleIn = InPort_RTC_TimedDouble_create("RTC_TimedDouble_in", _d_in_RTC_TimedDouble);
	if (RTC_addInPort(rtc, "RTC_TimedDouble_in", _in_RTC_TimedDoubleIn) < 0) {
		return -1;
	}

	_d_out_RTC_TimedDouble = RTC_TimedDouble_create();
	_out_RTC_TimedDoubleOut = OutPort_RTC_TimedDouble_create("RTC_TimedDouble_out", _d_out_RTC_TimedDouble);
	if (RTC_addOutPort(rtc, "RTC_TimedDouble_out", _out_RTC_TimedDoubleOut) < 0) {
		return -1;
	}

	_d_in_RTC_TimedString = RTC_TimedString_create();
	_in_RTC_TimedStringIn = InPort_RTC_TimedString_create("RTC_TimedString_in", _d_in_RTC_TimedString);
	if (RTC_addInPort(rtc, "RTC_TimedString_in", _in_RTC_TimedStringIn) < 0) {
		return -1;
	}

	_d_out_RTC_TimedString = RTC_TimedString_create();
	_out_RTC_TimedStringOut = OutPort_RTC_TimedString_create("RTC_TimedString_out", _d_out_RTC_TimedString);
	if (RTC_addOutPort(rtc, "RTC_TimedString_out", _out_RTC_TimedStringOut) < 0) {
		return -1;
	}

	_d_in_RTC_TimedLongSeq = RTC_TimedLongSeq_create();
	_in_RTC_TimedLongSeqIn = InPort_RTC_TimedLongSeq_create("RTC_TimedLongSeq_in", _d_in_RTC_TimedLongSeq);
	if (RTC_addInPort(rtc, "RTC_TimedLongSeq_in", _in_RTC_TimedLongSeqIn) < 0) {
		return -1;
	}

	_d_out_RTC_TimedLongSeq = RTC_TimedLongSeq_create();
	_out_RTC_TimedLongSeqOut = OutPort_RTC_TimedLongSeq_create("RTC_TimedLongSeq_out", _d_out_RTC_TimedLongSeq);
	if (RTC_addOutPort(rtc, "RTC_TimedLongSeq_out", _out_RTC_TimedLongSeqOut) < 0) {
		return -1;
	}

	_d_in_RTC_TimedDoubleSeq = RTC_TimedDoubleSeq_create();
	_in_RTC_TimedDoubleSeqIn = InPort_RTC_TimedDoubleSeq_create("RTC_TimedDoubleSeq_in", _d_in_RTC_TimedDoubleSeq);
	if (RTC_addInPort(rtc, "RTC_TimedDoubleSeq_in", _in_RTC_TimedDoubleSeqIn) < 0) {
		return -1;
	}

	_d_out_RTC_TimedDoubleSeq = RTC_TimedDoubleSeq_create();
	_out_RTC_TimedDoubleSeqOut = OutPort_RTC_TimedDoubleSeq_create("RTC_TimedDoubleSeq_out", _d_out_RTC_TimedDoubleSeq);
	if (RTC_addOutPort(rtc, "RTC_TimedDoubleSeq_out", _out_RTC_TimedDoubleSeqOut) < 0) {
		return -1;
	}

	return 0;
}

int on_activated(int ec_id) {
	printf("on_activated called.\n");
	return 0;
}

int on_deactivated(int ec_id) {
	printf("on_deactivated called.\n");
	return 0;
}

int on_execute(int ec_id) {
	int32_t flag;
	static int i;
	uint32_t sec, nsec;

	InPort_RTC_TimedLong_isNew(_in_RTC_TimedLongIn, &flag);
	if (flag) {
		InPort_read(_in_RTC_TimedLongIn, &flag);
		int32_t ld;
		RTC_TimedLong_get(_d_in_RTC_TimedLong, &sec, &nsec, &ld);
		printf("TimedLong : %d %d %d\n", sec, nsec, ld);
	}

	RTC_TimedLong_set(_d_out_RTC_TimedLong, 0, 0, i);
	OutPort_write(_out_RTC_TimedLongOut);

	InPort_RTC_TimedDouble_isNew(_in_RTC_TimedDoubleIn, &flag);
	if (flag) {
		InPort_read(_in_RTC_TimedDoubleIn, &flag);

		double dd;
		RTC_TimedDouble_get(_d_in_RTC_TimedDouble, &sec, &nsec, &dd);
		printf("TimedDouble : %d %d %f\n", sec, nsec, dd);
	}

	RTC_TimedDouble_set(_d_out_RTC_TimedDouble, 0, 0, i*0.1);
	OutPort_write(_out_RTC_TimedDoubleOut);

	InPort_RTC_TimedString_isNew(_in_RTC_TimedStringIn, &flag);
	if (flag) {
		InPort_read(_in_RTC_TimedStringIn, &flag);
		char stringBuf[256];
		RTC_TimedString_get(_d_in_RTC_TimedString, &sec, &nsec, stringBuf);
		printf("TimedString : %d %d %s\n", sec, nsec, stringBuf);
	}

	char stringBuffer[256];
	sprintf(stringBuffer, "TimedString Data is %d", i);
	RTC_TimedString_set(_d_out_RTC_TimedString, 0, 0, stringBuffer);
	OutPort_write(_out_RTC_TimedStringOut);

	InPort_RTC_TimedLongSeq_isNew(_in_RTC_TimedLongSeqIn, &flag);
	if (flag) {
		InPort_read(_in_RTC_TimedLongSeqIn, &flag);
		uint32_t len;
		RTC_TimedLongSeq_data_getLength(_d_in_RTC_TimedLongSeq, &len);

		int32_t* data = malloc(len * sizeof(int32_t));
		RTC_TimedLongSeq_get(_d_in_RTC_TimedLongSeq, &sec, &nsec, data, &len);
		printf("TimedLongSeq : \n");
		for (int i = 0; i < len; i++) {
			printf(" - %d\n", data[i]);
		}
		free(data);
	}

	RTC_TimedLongSeq_data_setLength(_d_out_RTC_TimedLongSeq, 3);
	int32_t ldata[3] = { i, i + 1, i + 2 };
	RTC_TimedLongSeq_set(_d_out_RTC_TimedLongSeq, 0, 0, ldata, 3);
	OutPort_write(_out_RTC_TimedLongSeqOut);


	InPort_RTC_TimedDoubleSeq_isNew(_in_RTC_TimedDoubleSeqIn, &flag);
	if (flag) {
		InPort_read(_in_RTC_TimedDoubleSeqIn, &flag);
		uint32_t len;
		RTC_TimedDoubleSeq_data_getLength(_d_in_RTC_TimedDoubleSeq, &len);

		double* data = malloc(len * sizeof(double));
		RTC_TimedDoubleSeq_get(_d_in_RTC_TimedDoubleSeq, &sec, &nsec, data, &len);
		printf("TimedDoubleSeq : \n");
		for (int i = 0; i < len; i++) {
			printf(" - %f\n", data[i]);
		}
		free(data);
	}


	RTC_TimedDoubleSeq_data_setLength(_d_out_RTC_TimedDoubleSeq, 3);
	double ddata[3] = { i*0.1, (i + 1)*0.1, (i + 2)*0.1 };
	RTC_TimedDoubleSeq_set(_d_out_RTC_TimedDoubleSeq, 0, 0, ddata, 3);
	OutPort_write(_out_RTC_TimedDoubleSeqOut);


	i++;
	return 0;
}