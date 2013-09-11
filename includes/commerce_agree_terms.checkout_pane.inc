<?php

/**
 * @file
 * Defines settings form and checkbox for checkout pane
 */

/**
 * Implements base_settings_form().
 */
function commerce_agree_terms_pane_settings_form($checkout_pane) {
  $form = array();
  
  $form['commerce_agree_terms_pane_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Pane title'),
    '#default_value' => variable_get('commerce_agree_terms_pane_title', t('Terms and Conditions')),
    '#required' => TRUE,
  );
  $form['commerce_agree_terms_pane_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Terms and Conditions path'),
    '#default_value' => variable_get('commerce_agree_terms_pane_node'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Implements base_checkout_form().
 */
function commerce_agree_terms_pane_checkout_form($form, $form_state, $checkout_pane, $order) {
  $checkout_form['commerce_agree_terms_pane_field_display'] = array(
    '#markup' => variable_get('commerce_agree_terms_pane_field', ''),
  );
  $checkout_form['commerce_agree_terms_pane_field'] = array(
    '#type' => 'checkbox',
    '#title' => t('I agree to the <a href="@url">@title</a>', array(
      '@url' => base_path() . variable_get('commerce_agree_terms_pane_node'),
      '@title' => variable_get('commerce_agree_terms_pane_title'),
    )),
    '#required' => TRUE,
  );
  return $checkout_form;
}
