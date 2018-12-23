<?php

function nuenenen_api_admin_settings($form, &$form_state) {
	$form['nuenenen_api_delete_expired_tokens'] = array(
		'#type' => 'checkbox',
		'#title' => t('Delete expired tokens.'),
		'#description' => t('Enable to delete expired tokens when trying to use an expired token and during cron runs.'),
		'#default_value' => variable_get('nuenenen_api_delete_expired_tokens', TRUE),
	);
	$form['advanced'] = array(
		'#type' => 'fieldset',
		'#title' => t('Advanced'),
		'#description' => t('Advanced configuration for the token authentication.'),
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);
	$form['advanced']['nuenenen_api_expiration_period'] = array(
		'#type' => 'textfield',
		'#title' => t('Expiration time'),
		'#description' => t('The period string compatible with <a href="@url">\DateInterval</a>.', array('@url' => 'http://php.net/manual/en/class.dateinterval.php')),
		'#default_value' => variable_get('nuenenen_api_expiration_period', 'P1D'),
		'#element_validate' => array('restful_date_time_format_element_validate'),
	);
	return system_settings_form($form);
}
