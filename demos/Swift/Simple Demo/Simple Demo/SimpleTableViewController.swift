//
//  SimpleTableViewController.swift
//  Simple Demo
//
//  Created by Muthu Arumugam on 10/7/15.
//  Copyright © 2015 Yieldmo, Inc. All rights reserved.
//

import UIKit

class SimpleTableViewController: UITableViewController, YMViewDelegate {
    
    var adContent = YMView()

    override func viewDidLoad() {
        super.viewDidLoad()

        YM.sharedYM().fetchNativePlacements([YMNativePlacement.init(placementId: kDemoDominoFormat4AdPlacementId, width: self.view.bounds.size.width)], delegate: self)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Table view data source

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 20
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell:UITableViewCell
        
        if  indexPath.row == Int(parallaxRowIndex()) {
            // For Yieldmo Ad Cell
            if (adContent is NilLiteralConvertible) {                
                cell = tableView.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath)
                cell.textLabel?.text = ""
            } else {
                cell = tableView.dequeueReusableCellWithIdentifier("placementCellId", forIndexPath: indexPath)
                cell.addSubview(adContent)
            }

        } else {
            cell = tableView.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath)
            cell.textLabel?.text = "Row \(indexPath.row)"
        }
        
        return cell
    }
    
    override func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        if  indexPath.row == Int(parallaxRowIndex()) {
            if (adContent is NilLiteralConvertible) {
                return 0.0; // Ad available
            } else {
                return self.adContent.preferredHeight; // No Ad
            }
        } else {
            return 40.0;
        }
    }

    // MARK: - YMViewDelegate methods
    
    func placementFailedToFetchAds(erroredPlacements: [AnyObject]!) {
        print("Failed to get ad from server for placements: \(erroredPlacements)")
        tableView!.reloadData()
    }
    
    func placementDidFetchAds(placementViews: [NSObject : AnyObject]!) {
        print("Successfully received an ad for \(placementViews.count) view(s)")
        adContent = placementViews[kDemoDominoFormat4AdPlacementId]! as! YMView
        tableView.reloadData()
    }
    
    override func scrollViewDidScroll(scrollView: UIScrollView) {
        adContent.didScroll()
    }
    
    func placementScrollView() -> UIScrollView! {
        return tableView;
    }
    
    func parallaxRowIndex() -> UInt {
        return 3;
    }
    
    // MARK: Prepare for Wrapper Demo
    @IBAction func wrapperButtonClicked(sender: AnyObject) {
        let wrapperPlacement = YMNativePlacement.init(placementId: kDemoWrapperFormatPlacementId, width: self.view.bounds.size.width)
        let storyboard = UIStoryboard.init(name: "Main", bundle: NSBundle.mainBundle())
        let wrapperViewController = storyboard.instantiateViewControllerWithIdentifier("wrapperdemo")
        let ymVC = YMWrapperViewController.init(childViewController: wrapperViewController, placements: [wrapperPlacement])
        self.navigationController?.pushViewController(ymVC, animated: true)
    }
    

}
