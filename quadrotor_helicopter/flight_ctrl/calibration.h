signed long eeprom_read_dword_(unsigned long addr)
{
	return eeprom_read_dword(addr);
}

void eeprom_write_dword_(unsigned long addr, unsigned long data)
{
	eeprom_write_dword(addr, data);
}

void load_calibration(calibration * c, unsigned long a)
{
	c->f_mot_adj = eeprom_read_dword_(a + f_mot_adj_addr + (4 * 0));
	c->b_mot_adj = eeprom_read_dword_(a + f_mot_adj_addr + (4 * 1));
	c->l_mot_adj = eeprom_read_dword_(a + f_mot_adj_addr + (4 * 2));
	c->r_mot_adj = eeprom_read_dword_(a + f_mot_adj_addr + (4 * 3));

	c->f_mot_scale = eeprom_read_dword_(a + f_mot_scale_addr + (4 * 0));
	c->b_mot_scale = eeprom_read_dword_(a + f_mot_scale_addr + (4 * 1));
	c->l_mot_scale = eeprom_read_dword_(a + f_mot_scale_addr + (4 * 2));
	c->r_mot_scale = eeprom_read_dword_(a + f_mot_scale_addr + (4 * 3));

	c->yaw_center_offset = eeprom_read_dword_(a + yaw_center_offset_addr + (4 * 0));
	c->pitch_center_offset = eeprom_read_dword_(a + yaw_center_offset_addr + (4 * 1));
	c->roll_center_offset = eeprom_read_dword_(a + yaw_center_offset_addr + (4 * 2));

	c->fb_accel_center_offset = eeprom_read_dword_(a + fb_accel_center_offset_addr + (4 * 0));
	c->lr_accel_center_offset = eeprom_read_dword_(a + fb_accel_center_offset_addr + (4 * 1));
	c->ud_accel_center_offset = eeprom_read_dword_(a + fb_accel_center_offset_addr + (4 * 2));

	c->fb_lr_accel_scale = eeprom_read_dword_(a + fb_lr_accel_scale_addr + (4 * 0));
	c->ud_accel_scale = eeprom_read_dword_(a + fb_lr_accel_scale_addr + (4 * 1));

	c->yaw_scale = eeprom_read_dword_(a + yaw_scale_addr + (4 * 0));

	for(unsigned char i = 0; i < 6; i++)
	{
		c->ppm_chan_offset[i] = eeprom_read_dword_(a + ppm_chan_offset_addr + (4 * i));
	}

	c->yaw_pid_kp = eeprom_read_dword_(a + yaw_pid_kp_addr + (4 * 0));
	c->yaw_pid_ki = eeprom_read_dword_(a + yaw_pid_kp_addr + (4 * 1));
	c->yaw_pid_kd = eeprom_read_dword_(a + yaw_pid_kp_addr + (4 * 2));
	c->yaw_pid_err_low_thresh = eeprom_read_dword_(a + yaw_pid_kp_addr + (4 * 3));
	c->yaw_pid_delta_err_low_thresh = eeprom_read_dword_(a + yaw_pid_kp_addr + (4 * 4));

	c->roll_pitch_a_pid_kp = eeprom_read_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 0));
	c->roll_pitch_a_pid_ki = eeprom_read_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 1));
	c->roll_pitch_a_pid_kd = eeprom_read_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 2));
	c->roll_pitch_a_pid_err_low_thresh = eeprom_read_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 3));
	c->roll_pitch_a_pid_delta_err_low_thresh = eeprom_read_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 4));

	c->roll_pitch_b_pid_kp = eeprom_read_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 0));
	c->roll_pitch_b_pid_ki = eeprom_read_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 1));
	c->roll_pitch_b_pid_kd = eeprom_read_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 2));
	c->roll_pitch_b_pid_err_low_thresh = eeprom_read_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 3));
	c->roll_pitch_b_pid_delta_err_low_thresh = eeprom_read_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 4));

	c->servo_pulse_scale = eeprom_read_dword_(a + servo_pulse_scale_addr + (4 * 0));
	c->servo_pulse_stop = eeprom_read_dword_(a + servo_pulse_scale_addr + (4 * 1));
	c->servo_period_delay = eeprom_read_dword_(a + servo_pulse_scale_addr + (4 * 2));

	c->throttle_scale = eeprom_read_dword_(a + throttle_scale_addr + (4 * 0));
	c->spin_scale = eeprom_read_dword_(a + throttle_scale_addr + (4 * 1));
	c->move_scale = eeprom_read_dword_(a + throttle_scale_addr + (4 * 2));

	c->yaw_sens_hist_len = eeprom_read_dword_(a + yaw_sens_hist_len_addr + (4 * 0));
	c->roll_pitch_sens_hist_len = eeprom_read_dword_(a + yaw_sens_hist_len_addr + (4 * 1));
	c->vert_accel_hist_len = eeprom_read_dword_(a + yaw_sens_hist_len_addr + (4 * 2));
	c->hori_accel_hist_len = eeprom_read_dword_(a + yaw_sens_hist_len_addr + (4 * 3));

	c->hover_throttle = eeprom_read_dword_(a + hover_throttle_addr + (4 * 0));
}

void save_calibration(calibration c, unsigned long a)
{
	eeprom_write_dword_(a + f_mot_adj_addr + (4 * 0), c.f_mot_adj);
	eeprom_write_dword_(a + f_mot_adj_addr + (4 * 1), c.b_mot_adj);
	eeprom_write_dword_(a + f_mot_adj_addr + (4 * 2), c.l_mot_adj);
	eeprom_write_dword_(a + f_mot_adj_addr + (4 * 3), c.r_mot_adj);

	eeprom_write_dword_(a + f_mot_scale_addr + (4 * 0), c.f_mot_scale);
	eeprom_write_dword_(a + f_mot_scale_addr + (4 * 1), c.b_mot_scale);
	eeprom_write_dword_(a + f_mot_scale_addr + (4 * 2), c.l_mot_scale);
	eeprom_write_dword_(a + f_mot_scale_addr + (4 * 3), c.r_mot_scale);

	eeprom_write_dword_(a + yaw_center_offset_addr + (4 * 0), c.yaw_center_offset);
	eeprom_write_dword_(a + yaw_center_offset_addr + (4 * 1), c.pitch_center_offset);
	eeprom_write_dword_(a + yaw_center_offset_addr + (4 * 2), c.roll_center_offset);

	eeprom_write_dword_(a + fb_accel_center_offset_addr + (4 * 0), c.fb_accel_center_offset);
	eeprom_write_dword_(a + fb_accel_center_offset_addr + (4 * 1), c.lr_accel_center_offset);
	eeprom_write_dword_(a + fb_accel_center_offset_addr + (4 * 2), c.ud_accel_center_offset);

	eeprom_write_dword_(a + yaw_scale_addr + (4 * 0), c.yaw_scale);
	eeprom_write_dword_(a + yaw_scale_addr + (4 * 1), c.roll_pitch_scale);

	eeprom_write_dword_(a + fb_lr_accel_scale_addr + (4 * 0), c.fb_lr_accel_scale);
	eeprom_write_dword_(a + fb_lr_accel_scale_addr + (4 * 1), c.ud_accel_scale);

	for(unsigned char i = 0; i < 8; i++)
	{
		eeprom_write_dword_(a + ppm_chan_offset_addr + (4 * i), c.ppm_chan_offset[i]);
	}

	eeprom_write_dword_(a + yaw_pid_kp_addr + (4 * 0), c.yaw_pid_kp);
	eeprom_write_dword_(a + yaw_pid_kp_addr + (4 * 1), c.yaw_pid_ki);
	eeprom_write_dword_(a + yaw_pid_kp_addr + (4 * 2), c.yaw_pid_kd);
	eeprom_write_dword_(a + yaw_pid_kp_addr + (4 * 3), c.yaw_pid_err_low_thresh);
	eeprom_write_dword_(a + yaw_pid_kp_addr + (4 * 4), c.yaw_pid_delta_err_low_thresh);

	eeprom_write_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 0), c.roll_pitch_a_pid_kp);
	eeprom_write_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 1), c.roll_pitch_a_pid_ki);
	eeprom_write_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 2), c.roll_pitch_a_pid_kd);
	eeprom_write_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 3), c.roll_pitch_a_pid_err_low_thresh);
	eeprom_write_dword_(a + roll_pitch_a_pid_kp_addr + (4 * 4), c.roll_pitch_a_pid_delta_err_low_thresh);

	eeprom_write_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 0), c.roll_pitch_b_pid_kp);
	eeprom_write_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 1), c.roll_pitch_b_pid_ki);
	eeprom_write_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 2), c.roll_pitch_b_pid_kd);
	eeprom_write_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 3), c.roll_pitch_b_pid_err_low_thresh);
	eeprom_write_dword_(a + roll_pitch_b_pid_kp_addr + (4 * 4), c.roll_pitch_b_pid_delta_err_low_thresh);

	eeprom_write_dword_(a + servo_pulse_scale_addr + (4 * 0), c.servo_pulse_scale);
	eeprom_write_dword_(a + servo_pulse_scale_addr + (4 * 1), c.servo_pulse_stop);
	eeprom_write_dword_(a + servo_pulse_scale_addr + (4 * 2), c.servo_period_delay);

	eeprom_write_dword_(a + throttle_scale_addr + (4 * 0), c.throttle_scale);
	eeprom_write_dword_(a + throttle_scale_addr + (4 * 1), c.spin_scale);
	eeprom_write_dword_(a + throttle_scale_addr + (4 * 3), c.move_scale);

	eeprom_write_dword_(a + yaw_sens_hist_len_addr + (4 * 0), c.yaw_sens_hist_len);
	eeprom_write_dword_(a + yaw_sens_hist_len_addr + (4 * 1), c.roll_pitch_sens_hist_len);
	eeprom_write_dword_(a + yaw_sens_hist_len_addr + (4 * 2), c.vert_accel_hist_len);
	eeprom_write_dword_(a + yaw_sens_hist_len_addr + (4 * 3), c.hori_accel_hist_len);

	eeprom_write_dword_(a + hover_throttle_addr + (4 * 3), c.hover_throttle);
}

void default_calibration(calibration * c)
{
	c->f_mot_adj = f_mot_adj_default;
	c->b_mot_adj = b_mot_adj_default;
	c->l_mot_adj = l_mot_adj_default;
	c->r_mot_adj = r_mot_adj_default;

	c->f_mot_scale = f_mot_scale_default;
	c->b_mot_scale = b_mot_scale_default;
	c->l_mot_scale = l_mot_scale_default;
	c->r_mot_scale = r_mot_scale_default;

	c->yaw_center_offset = yaw_center_offset_default;
	c->pitch_center_offset = pitch_center_offset_default;
	c->roll_center_offset = roll_center_offset_default;

	c->yaw_scale = yaw_scale_default;
	c->roll_pitch_scale = roll_pitch_scale_default;

	c->fb_accel_center_offset = fb_accel_center_offset_default;
	c->lr_accel_center_offset = lr_accel_center_offset_default;
	c->ud_accel_center_offset = ud_accel_center_offset_default;

	c->fb_lr_accel_scale = fb_lr_accel_scale_default;
	c->ud_accel_scale = ud_accel_scale_default;

	for(unsigned char i = 0; i < 6; i++)
	{
		c->ppm_chan_offset[i] = ppm_chan_offset_default;
	}

	c->yaw_pid_kp = yaw_pid_kp_default;
	c->yaw_pid_ki = yaw_pid_ki_default;
	c->yaw_pid_kd = yaw_pid_kd_default;
	c->yaw_pid_err_low_thresh = yaw_pid_err_low_thresh_default;
	c->yaw_pid_delta_err_low_thresh = yaw_pid_delta_err_low_thresh_default;

	c->roll_pitch_a_pid_kp = roll_pitch_a_pid_kp_default;
	c->roll_pitch_a_pid_ki = roll_pitch_a_pid_ki_default;
	c->roll_pitch_a_pid_kd = roll_pitch_a_pid_kd_default;
	c->roll_pitch_a_pid_err_low_thresh = roll_pitch_a_pid_err_low_thresh_default;
	c->roll_pitch_a_pid_delta_err_low_thresh = roll_pitch_a_pid_delta_err_low_thresh_default;

	c->roll_pitch_b_pid_kp = roll_pitch_b_pid_kp_default;
	c->roll_pitch_b_pid_ki = roll_pitch_b_pid_ki_default;
	c->roll_pitch_b_pid_kd = roll_pitch_b_pid_kd_default;
	c->roll_pitch_b_pid_err_low_thresh = roll_pitch_b_pid_err_low_thresh_default;
	c->roll_pitch_b_pid_delta_err_low_thresh = roll_pitch_b_pid_delta_err_low_thresh_default;

	c->servo_pulse_scale = servo_pulse_scale_default;
	c->servo_pulse_stop = servo_pulse_stop_default;
	c->servo_period_delay = servo_period_delay_default;

	c->throttle_scale = throttle_scale_default;
	c->spin_scale = spin_scale_default;
	c->move_scale = move_scale_default;

	c->yaw_sens_hist_len = yaw_sens_hist_len_default;
	c->roll_pitch_sens_hist_len = roll_pitch_sens_hist_len_default;
	c->vert_accel_hist_len = vert_accel_hist_len_default;
	c->hori_accel_hist_len = hori_accel_hist_len_default;

	c->hover_throttle = hover_throttle_default;
}

void calibrate_sensors(calibration * c)
{
	signed long adcr[8];
	unsigned long cnt;

	for(unsigned char i = 0, cnt = 0; i < 8; i++, cnt = 0)
	{
		unsigned long sum = 0;

		while(adcr[i] < 1000000)
		{
			loop_until_bit_is_clear(ADCSRA, ADSC);
			sum += ADC;
			cnt++;
			ADMUX = (ADMUX & 0b11100000) | ADC_chan_cnt;
			ADCSRA = _BV(ADEN) | _BV(ADSC) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
		}

		unsigned long avg = scale(sum, 1, cnt);
		adcr[i] = avg;
	}

	c->yaw_center_offset = adcr[yaw_sens_chan];
	c->roll_center_offset = adcr[roll_sens_chan];
	c->pitch_center_offset = adcr[pitch_sens_chan];

	c->fb_accel_center_offset = adcr[fb_accel_chan];
	c->lr_accel_center_offset = adcr[lr_accel_chan];
	c->ud_accel_center_offset = adcr[ud_accel_chan];
}

void calibrate_controller(calibration * c)
{
	ppm_data pd;
	signed long sum[8];
	unsigned long cnt;
	for(unsigned char i = 0; i < 8; i++)
	{
		pd.chan_offset[i] = 0;
		sum[i] = 0;
	}
	for(cnt = 0; cnt < 10; cnt++)
	{
		while(pd.tx_good == 0)
		{
			if(bit_is_set(TIFR1, ICF1))
			{
				timer_1_input_capture(&pd);
				TIFR1 |= _BV(ICF1);
			}
			if(bit_is_set(TIFR1, TOV1))
			{
				timer_1_ovf(&pd);
				TIFR1 |= _BV(TOV1);
			}
		}
		pd.tx_good = 0;
		for(unsigned char i = 0; i < 8; i++)
		{
			sum[i] += pd.chan_width[i];
		}
	}
	for(unsigned char i = 0; i < 8; i++)
	{
		c->ppm_chan_offset[i] = scale(sum[i], 1, cnt);
	}
}

void apply_calibration(calibration c)
{
	motor_cali.f_mot_tweak = c.f_mot_adj;
	motor_cali.b_mot_tweak = c.b_mot_adj;
	motor_cali.l_mot_tweak = c.l_mot_adj;
	motor_cali.r_mot_tweak = c.r_mot_adj;

	motor_cali.f_mot_scale = c.f_mot_scale;
	motor_cali.b_mot_scale = c.b_mot_scale;
	motor_cali.l_mot_scale = c.l_mot_scale;
	motor_cali.r_mot_scale = c.r_mot_scale;

	motor_cali.servo_pulse_scale = c.servo_pulse_scale;
	motor_cali.servo_stop = c.servo_pulse_stop;

	sens_data[yaw_sens_chan].centering_offset = c.yaw_center_offset;
	sens_data[roll_sens_chan].centering_offset = c.roll_center_offset;
	sens_data[pitch_sens_chan].centering_offset = c.pitch_center_offset;

	sens_data[fb_accel_chan].centering_offset = c.fb_accel_center_offset;
	sens_data[lr_accel_chan].centering_offset = c.lr_accel_center_offset;
	sens_data[ud_accel_chan].centering_offset = c.ud_accel_center_offset;

	sens_data[yaw_sens_chan].sens_history_length = c.yaw_sens_hist_len;
	sens_data[roll_sens_chan].sens_history_length = c.roll_pitch_sens_hist_len;
	sens_data[pitch_sens_chan].sens_history_length = c.roll_pitch_sens_hist_len;

	sens_data[fb_accel_chan].sens_history_length = c.hori_accel_hist_len;
	sens_data[lr_accel_chan].sens_history_length = c.hori_accel_hist_len;
	sens_data[ud_accel_chan].sens_history_length = c.vert_accel_hist_len;

	yaw_pid.constants.kp = c.yaw_pid_kp;
	yaw_pid.constants.ki = c.yaw_pid_ki;
	yaw_pid.constants.kd = c.yaw_pid_kd;
	yaw_pid.constants.err_low_thresh = c.yaw_pid_err_low_thresh;
	yaw_pid.constants.delta_err_low_thresh = c.yaw_pid_delta_err_low_thresh;

	pitch_pid_a.constants.kp = c.roll_pitch_a_pid_kp;
	pitch_pid_a.constants.ki = c.roll_pitch_a_pid_ki;
	pitch_pid_a.constants.kd = c.roll_pitch_a_pid_kd;
	pitch_pid_a.constants.err_low_thresh = c.roll_pitch_a_pid_err_low_thresh;
	pitch_pid_a.constants.delta_err_low_thresh = c.roll_pitch_a_pid_delta_err_low_thresh;

	roll_pid_a.constants.kp = c.roll_pitch_a_pid_kp;
	roll_pid_a.constants.ki = c.roll_pitch_a_pid_ki;
	roll_pid_a.constants.kd = c.roll_pitch_a_pid_kd;
	roll_pid_a.constants.err_low_thresh = c.roll_pitch_a_pid_err_low_thresh;
	roll_pid_a.constants.delta_err_low_thresh = c.roll_pitch_a_pid_delta_err_low_thresh;

	pitch_pid_b.constants.kp = c.roll_pitch_b_pid_kp;
	pitch_pid_b.constants.ki = c.roll_pitch_b_pid_ki;
	pitch_pid_b.constants.kd = c.roll_pitch_b_pid_kd;
	pitch_pid_b.constants.err_low_thresh = c.roll_pitch_b_pid_err_low_thresh;
	pitch_pid_b.constants.delta_err_low_thresh = c.roll_pitch_b_pid_delta_err_low_thresh;

	roll_pid_b.constants.kp = c.roll_pitch_b_pid_kp;
	roll_pid_b.constants.ki = c.roll_pitch_b_pid_ki;
	roll_pid_b.constants.kd = c.roll_pitch_b_pid_kd;
	roll_pid_b.constants.err_low_thresh = c.roll_pitch_b_pid_err_low_thresh;
	roll_pid_b.constants.delta_err_low_thresh = c.roll_pitch_b_pid_delta_err_low_thresh;

	for(unsigned char i = 0; i < 8; i++)
	{
		vex_data.chan_offset[i] = c.ppm_chan_offset;
	}
}

