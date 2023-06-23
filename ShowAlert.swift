//
//  ShowAlert.swift
//  Alert_Testing
//
//  Created by ShafiulAlam-00058 on 6/23/23.
//

import Foundation
import UIKit


extension UIViewController {
		
	public func showAlert(title: String, message: String, completion: @escaping (() -> Void) = {}) {
		let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
		let action = UIAlertAction(title: "OK", style: .default) { _ in
			completion()
		}
		alert.addAction(action)
		present(alert, animated: true)
	}
	
	public func popUpAlert( title: String, message: String, timeInSec time: Int) {
		let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
		present(alert, animated: true)
		Timer.scheduledTimer(withTimeInterval: TimeInterval(time), repeats: false) { timer in
			alert.dismiss(animated: true)
			timer.invalidate()
		}
	}
}

