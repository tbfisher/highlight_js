<?php
/**
 * @file
 * Administrative page callbacks for the highlight.js module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function highlight_js_settings_form($form_state) {
  $form['highlight_js_theme'] = array(
    '#type' => 'select',
    '#title' => t('Themes'),
    '#description' => t('Select a theme you would like to apply on code sections. For more details regarding these themes, pay a visit to !url', array('!url' => '')),
    '#default_value' => variable_get('highlight_js_theme', 'default'),
    '#options' => array(
      'default' => 'default',
      'arta' => 'arta',
      'ascetic' => 'ascetic',
      'brown_paper' => 'brown_paper',
      'dark' => 'dark',
      'default' => 'default',
      'far' => 'far',
      'github' => 'github',
      'googlecode' => 'googlecode',
      'idea' => 'idea',
      'ir_black' => 'ir_black',
      'magula' => 'magula',
      'monokai' => 'monokai',
      'pojoaque' => 'pojoaque',
      'rainbow' => 'rainbow',
      'school_book' => 'school_book',
      'solarized_dark' => 'solarized_dark',
      'solarized_light' => 'solarized_light',
      'sunburst' => 'sunburst',
      'tomorrow-night-blue' => 'tomorrow-night-blue',
      'tomorrow-night-bright' => 'tomorrow-night-bright',
      'tomorrow-night-eighties' => 'tomorrow-night-eighties',
      'tomorrow-night' => 'tomorrow-night',
      'tomorrow' => 'tomorrow',
      'vs' => 'vs',
      'xcode' => 'xcode',
      'zenburn' => 'zenburn',
      '' => '- Custom -'
    ),
  );

  $form['highlight_js_theme_path'] = array(
    '#title' => t('Path to a custom theme'),
    '#type' => 'textfield',
    '#default_value' => variable_get('highlight_js_theme_path', ''),
    '#states' => array(
      // Only show this field when the theme is set to custom.
      'visible' => array(
        ':input[name="highlight_js_theme"]' => array('value' => ''),
      ),
    ),
    '#description' => t('If you select to use a custom theme you can use this settings to specify where your CSS file is located relative to the Drupal root. Leave blank if you want to load no file (may be useful if you want to define this in your Drupal theme).'),
  );

  $form['highlight_js_use_online'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use online version of highlight.js'),
    '#description' => t('When checked, use the online minified version of highlight.js hosted by Yandex. If you uncheck this, you will need to download the highlight.js library and install it in the module folder; see INSTALL.txt.'),
    '#default_value' => variable_get('highlight_js_use_online', 1),
  );

  return system_settings_form($form);
}