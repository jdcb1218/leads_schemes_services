<?php

function leads_schemes_services_resource() {
  $api = array(
	'leads_schemes' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Retrieves leads schemes info.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'leads_schemes_services',
        	'name' => 'includes/leads_schemes.services',
      	),
      	'callback' => 'leads_schemes_services_resource_retrieve',
      	'access callback' => 'user_access',
      	'access arguments' => array('access content'),
      	'access arguments append' => FALSE,
      	'args' => array(
        	array(
          	'name' => 'nid',
          	'type' => 'int',
          	'description' => 'Function to perform',
          	'source' => array(
            	'path' => '0'
          	),
          	'optional' => TRUE,
          	'default' => '0',
        	),
      	),
    	),
      	),
	),
  );
  return $api;
}

/**
 * [leads_schemes_services_resource_retrieve] definition.
 * Returns the information about a leads scheme.
 * @param $nid
 *   The nid of the leads_scheme node.
 * @return array
 *	The node processed information array.
 */

/* 
	$get_leads = file_get_contents('http://w.creg-old.com/cf_api/leads_schemes/104.json');
	$storage = json_decode($get_leads);
	dpm($storage);
*/

function leads_schemes_services_resource_retrieve($nid) {
  
  $leads = array();

	if (isset($nid)) {
		$query = new EntityFieldQuery();
	  $result = $query
	    ->entityCondition('entity_type', 'registration')
	    ->propertyCondition('entity_id', $nid)
	    ->propertyCondition('entity_type', 'node')
	    ->execute();
	}
	if ($result['registration']) {
			foreach ($result['registration'] as $key => $value) {
				$registration_load = registration_load($key);
				$leads[$key] = $registration_load;
			}		
	}
	 return $leads;
}
